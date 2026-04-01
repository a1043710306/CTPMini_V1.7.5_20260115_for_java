#!/usr/bin/env bash
# build_linux.sh - Build CTP Mini Java JNI library on Linux x64
# Supports: Ubuntu/Debian, RHEL/CentOS/Fedora, Arch, Alpine
# Requirements:
#   - CMake  >= 3.14
#   - SWIG   >= 3.0
#   - JDK    8+
#   - g++ or clang++

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build_linux64"
INSTALL_DIR="${SCRIPT_DIR}/install_linux64"

# ── colour helpers ────────────────────────────────────────────
RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'; NC='\033[0m'
ok()   { echo -e "${GREEN}[OK]${NC}    $*"; }
warn() { echo -e "${YELLOW}[WARN]${NC}  $*"; }
err()  { echo -e "${RED}[ERROR]${NC} $*"; }

echo "========================================"
echo "  CTP Mini Java -- Linux x64 build"
echo "========================================"

# ── 1. Detect OS / package manager ───────────────────────────
detect_os() {
    if   [ -f /etc/os-release ]; then
        . /etc/os-release
        OS_ID="${ID:-unknown}"
        OS_LIKE="${ID_LIKE:-}"
    elif [ -f /etc/redhat-release ]; then
        OS_ID="rhel"
    elif [ -f /etc/arch-release ]; then
        OS_ID="arch"
    elif [ -f /etc/alpine-release ]; then
        OS_ID="alpine"
    else
        OS_ID="unknown"
    fi
}
detect_os

pkg_hint() {
    local pkg_deb="$1" pkg_rpm="$2" pkg_arch="${3:-$1}" pkg_apk="${4:-$1}"
    case "$OS_ID" in
        ubuntu|debian|linuxmint|pop) echo "  sudo apt-get install -y $pkg_deb" ;;
        rhel|centos|rocky|almalinux) echo "  sudo yum install -y $pkg_rpm" ;;
        fedora)                       echo "  sudo dnf install -y $pkg_rpm" ;;
        arch|manjaro)                 echo "  sudo pacman -S $pkg_arch" ;;
        alpine)                       echo "  sudo apk add $pkg_apk" ;;
        *)                            echo "  (install $pkg_deb / $pkg_rpm)" ;;
    esac
}

# ── 2. Check cmake ────────────────────────────────────────────
if ! command -v cmake &>/dev/null; then
    err "cmake not found in PATH."
    pkg_hint "cmake" "cmake" "cmake" "cmake"
    exit 1
fi
CMAKE_VER="$(cmake --version | awk 'NR==1{print $3}')"
# Require >= 3.14
CMAKE_MAJOR="${CMAKE_VER%%.*}"
CMAKE_MINOR="${CMAKE_VER#*.}"; CMAKE_MINOR="${CMAKE_MINOR%%.*}"
if [ "$CMAKE_MAJOR" -lt 3 ] || { [ "$CMAKE_MAJOR" -eq 3 ] && [ "$CMAKE_MINOR" -lt 14 ]; }; then
    err "CMake $CMAKE_VER found, but >= 3.14 is required."
    exit 1
fi
ok "CMake $CMAKE_VER"

# ── 3. Check SWIG ─────────────────────────────────────────────
if ! command -v swig &>/dev/null; then
    err "swig not found in PATH."
    pkg_hint "swig" "swig" "swig" "swig"
    exit 1
fi
SWIG_VER="$(swig -version 2>&1 | awk '/SWIG Version/{print $3}')"
ok "SWIG $SWIG_VER"

# ── 4. Detect C++ compiler ────────────────────────────────────
CXX_COMPILER=""
CXX_NAME=""

# Prefer g++ → clang++ → c++
for cxx in g++ clang++ c++; do
    if command -v "$cxx" &>/dev/null; then
        CXX_COMPILER="$(command -v "$cxx")"
        CXX_NAME="$cxx"
        CXX_VER="$("$cxx" --version 2>&1 | head -1)"
        break
    fi
done

if [ -z "$CXX_COMPILER" ]; then
    err "No C++ compiler found (tried g++, clang++, c++)."
    pkg_hint "g++" "gcc-c++" "gcc" "g++"
    exit 1
fi
ok "C++ compiler: $CXX_VER"

# Pick matching cmake generator
# Use Ninja if available (faster), otherwise Unix Makefiles
CMAKE_GENERATOR="Unix Makefiles"
MAKE_CMD="make"
JOBS="$(nproc 2>/dev/null || echo 4)"

if command -v ninja &>/dev/null; then
    CMAKE_GENERATOR="Ninja"
    MAKE_CMD="ninja"
    NINJA_VER="$(ninja --version 2>/dev/null || echo '?')"
    ok "Build tool: Ninja $NINJA_VER"
else
    MAKE_VER="$(make --version 2>&1 | head -1)"
    ok "Build tool: $MAKE_VER"
fi

# ── 5. Auto-detect JAVA_HOME ──────────────────────────────────
if [ -z "${JAVA_HOME:-}" ]; then
    # Strategy 1: java binary in PATH
    if command -v java &>/dev/null; then
        _JAVA_BIN="$(command -v java)"
        # Resolve symlinks
        if command -v readlink &>/dev/null; then
            _JAVA_BIN="$(readlink -f "$_JAVA_BIN" 2>/dev/null || echo "$_JAVA_BIN")"
        fi
        JAVA_HOME="${_JAVA_BIN%/bin/java}"
    fi

    # Strategy 2: java-config (Gentoo / some Debian setups)
    if [ -z "${JAVA_HOME:-}" ] && command -v java-config &>/dev/null; then
        JAVA_HOME="$(java-config --jdk-home 2>/dev/null || true)"
    fi

    # Strategy 3: update-java-alternatives (Debian/Ubuntu)
    if [ -z "${JAVA_HOME:-}" ] && command -v update-java-alternatives &>/dev/null; then
        _JALT="$(update-java-alternatives -l 2>/dev/null | awk '{print $3}' | head -1)"
        [ -n "$_JALT" ] && JAVA_HOME="$_JALT"
    fi

    # Strategy 4: well-known directories
    if [ -z "${JAVA_HOME:-}" ]; then
        for _d in \
            /usr/lib/jvm/java-*-openjdk-amd64 \
            /usr/lib/jvm/java-*-openjdk \
            /usr/lib/jvm/default-java \
            /usr/lib/jvm/default \
            /usr/java/default \
            /usr/java/latest \
            /opt/java/* \
            /opt/jdk/*
        do
            if [ -d "$_d" ] && [ -x "$_d/bin/javac" ]; then
                JAVA_HOME="$_d"
                break
            fi
        done
    fi
fi

# Strip trailing /jre (JDK 8 layout)
JAVA_HOME="${JAVA_HOME%/jre}"

if [ -z "${JAVA_HOME:-}" ]; then
    err "Could not detect JAVA_HOME. Set it manually:"
    echo "  export JAVA_HOME=/path/to/your/jdk"
    exit 1
fi
if [ ! -x "${JAVA_HOME}/bin/javac" ]; then
    err "JAVA_HOME=${JAVA_HOME} does not contain bin/javac."
    echo "  Make sure JAVA_HOME points to a JDK (not a JRE)."
    exit 1
fi
JAVA_VER="$("${JAVA_HOME}/bin/java" -version 2>&1 | head -1)"
ok "JAVA_HOME=${JAVA_HOME}  ($JAVA_VER)"

# ── 6. Configure ──────────────────────────────────────────────
mkdir -p "${BUILD_DIR}"
pushd "${BUILD_DIR}" > /dev/null

echo ""
echo "[INFO] Configuring with generator: ${CMAKE_GENERATOR}"
cmake "${SCRIPT_DIR}" \
    -G "${CMAKE_GENERATOR}" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_COMPILER="${CXX_COMPILER}" \
    -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
    -DJAVA_HOME="${JAVA_HOME}" \
    -DBUILD_MD_API=ON \
    -DBUILD_TRADE_API=ON

# ── 7. Build ──────────────────────────────────────────────────
echo ""
echo "[INFO] Building with ${JOBS} parallel jobs..."
if [ "$CMAKE_GENERATOR" = "Ninja" ]; then
    cmake --build . -- -j"${JOBS}"
else
    cmake --build . -- -j"${JOBS}"
fi

# ── 8. Install ────────────────────────────────────────────────
cmake --install .

popd > /dev/null

echo ""
echo "========================================"
echo "  Build successful!"
echo "  Generator  : ${CMAKE_GENERATOR}"
echo "  Compiler   : ${CXX_NAME}"
echo "  JAVA_HOME  : ${JAVA_HOME}"
echo "  JNI .so    : ${INSTALL_DIR}/lib"
echo "  JAR file   : ${INSTALL_DIR}/lib/java/ctpmini-java.jar"
echo "  Java source: ${INSTALL_DIR}/java/src"
echo "========================================"
