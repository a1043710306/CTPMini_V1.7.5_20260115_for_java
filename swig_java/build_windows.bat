@echo off
REM build_windows.bat - Build CTP Mini Java JNI library on Windows x64
REM Requirements:
REM   - CMake  >= 3.14  (in PATH)
REM   - SWIG   >= 3.0   (in PATH)
REM   - JDK    8+       (JAVA_HOME set or auto-detected)
REM   - Visual Studio 2015/2017/2019/2022/2026  OR  MinGW-w64

setlocal EnableDelayedExpansion

set SCRIPT_DIR=%~dp0
set BUILD_DIR=%SCRIPT_DIR%build_win64
set INSTALL_DIR=%SCRIPT_DIR%install_win64

echo ========================================
echo  CTP Mini Java -- Windows x64 build
echo ========================================

:: ------------------------------------------------
:: 1. Check CMake
:: ------------------------------------------------
where cmake >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] cmake not found in PATH.
    echo   Download: https://cmake.org/download/
    exit /b 1
)
for /f "tokens=3" %%v in ('cmake --version 2^>^&1 ^| findstr /i "version"') do set CMAKE_VER=%%v
echo [OK] CMake %CMAKE_VER%

:: ------------------------------------------------
:: 2. Check SWIG
:: ------------------------------------------------
where swig >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] swig not found in PATH.
    echo   Download: https://www.swig.org/download.html
    exit /b 1
)
for /f "tokens=3" %%v in ('swig -version 2^>^&1 ^| findstr /i "version"') do set SWIG_VER=%%v
echo [OK] SWIG %SWIG_VER%

:: ------------------------------------------------
:: 3. Auto-detect JAVA_HOME
:: ------------------------------------------------
if not defined JAVA_HOME (
    echo [INFO] JAVA_HOME not set, trying auto-detect...
    for /f "usebackq tokens=*" %%j in (`where java 2^>nul`) do (
        set _JAVA_EXE=%%j
        goto :found_java
    )
    echo [ERROR] java not found in PATH and JAVA_HOME is not set.
    exit /b 1
    :found_java
    REM java.exe -> bin\java.exe -> strip \bin\java.exe
    set JAVA_HOME=!_JAVA_EXE:\bin\java.exe=!
    if "!JAVA_HOME!"=="!_JAVA_EXE!" set JAVA_HOME=!_JAVA_EXE:\bin\java=!
)
REM Verify javac exists under JAVA_HOME
if not exist "%JAVA_HOME%\bin\javac.exe" (
    echo [ERROR] JAVA_HOME=%JAVA_HOME% does not contain bin\javac.exe
    echo         Make sure JAVA_HOME points to a JDK, not a JRE.
    exit /b 1
)
echo [OK] JAVA_HOME=%JAVA_HOME%

:: ------------------------------------------------
:: 4. Auto-detect Visual Studio generator
::    Probe vswhere (bundled with VS 2017+) first,
::    then fall back to registry keys for older VS.
:: ------------------------------------------------
set VS_GENERATOR=
set VS_YEAR=

REM -- Try vswhere (VS 2017 / 2019 / 2022 / 2026) --
set VSWHERE="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist %VSWHERE% set VSWHERE="%ProgramFiles%\Microsoft Visual Studio\Installer\vswhere.exe"

if exist %VSWHERE% (
    REM Get the latest VS installation path
    for /f "usebackq tokens=*" %%p in (
        `%VSWHERE% -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationVersion 2^>nul`
    ) do set VS_FULL_VER=%%p

    if defined VS_FULL_VER (
        REM Major version number
        for /f "tokens=1 delims=." %%m in ("!VS_FULL_VER!") do set VS_MAJOR=%%m

        if "!VS_MAJOR!"=="18" (
            set VS_GENERATOR=Visual Studio 18 2026
            set VS_YEAR=2026
        ) else if "!VS_MAJOR!"=="17" (
            set VS_GENERATOR=Visual Studio 17 2022
            set VS_YEAR=2022
        ) else if "!VS_MAJOR!"=="16" (
            set VS_GENERATOR=Visual Studio 16 2019
            set VS_YEAR=2019
        ) else if "!VS_MAJOR!"=="15" (
            set VS_GENERATOR=Visual Studio 15 2017
            set VS_YEAR=2017
        )
    )
)

REM -- Fallback: probe registry for VS 2015 / 2013 -
if not defined VS_GENERATOR (
    reg query "HKLM\SOFTWARE\Microsoft\VisualStudio\14.0" >nul 2>&1
    if !ERRORLEVEL! EQU 0 (
        set VS_GENERATOR=Visual Studio 14 2015
        set VS_YEAR=2015
    )
)
if not defined VS_GENERATOR (
    reg query "HKLM\SOFTWARE\WOW6432Node\Microsoft\VisualStudio\14.0" >nul 2>&1
    if !ERRORLEVEL! EQU 0 (
        set VS_GENERATOR=Visual Studio 14 2015
        set VS_YEAR=2015
    )
)

REM -- Last resort: MinGW Makefiles ----------------
if not defined VS_GENERATOR (
    where mingw32-make >nul 2>&1
    if !ERRORLEVEL! EQU 0 (
        set VS_GENERATOR=MinGW Makefiles
        set VS_YEAR=MinGW
        echo [INFO] No Visual Studio found. Using MinGW Makefiles.
    )
)

if not defined VS_GENERATOR (
    echo [ERROR] No supported toolchain found.
    echo   Install Visual Studio 2015/2017/2019/2022/2026 with "Desktop development with C++"
    echo   OR install MinGW-w64 and add to PATH.
    exit /b 1
)
echo [OK] Generator: %VS_GENERATOR%

:: ------------------------------------------------
:: 5. Build architecture flag
:: ------------------------------------------------
REM VS 2015 uses "Generator Win64" suffix; newer VS use -A x64; MinGW needs nothing
set VS_ARCH_FLAG=
if not "!VS_YEAR!"=="MinGW" (
    if "!VS_YEAR!"=="2015" (
        REM Append Win64 directly into the generator name
        set VS_GENERATOR=!VS_GENERATOR! Win64
    ) else (
        set VS_ARCH_FLAG=-A x64
    )
)

:: ------------------------------------------------
:: 6 / 7 / 8. Configure + Build + Install
::    Delegate to PowerShell to avoid cmd quoting bugs
::    with generator names that contain spaces.
:: ------------------------------------------------
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

echo.
echo [INFO] Configuring CMake...
echo   Source    : %SCRIPT_DIR%
echo   Generator : !VS_GENERATOR!
echo   Arch flag : !VS_ARCH_FLAG!
echo.

powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "$gen  = '!VS_GENERATOR!';" ^
  "$arch = '!VS_ARCH_FLAG!';" ^
  "$src  = '!SCRIPT_DIR!';" ^
  "$bld  = '!BUILD_DIR!';" ^
  "$inst = '!INSTALL_DIR!';" ^
  "$args = @('-G', $gen);" ^
  "if ($arch) { $args += $arch.Split(' ', [System.StringSplitOptions]::RemoveEmptyEntries) };" ^
  "$args += @('-DCMAKE_INSTALL_PREFIX=' + $inst, '-DBUILD_MD_API=ON', '-DBUILD_TRADE_API=ON');" ^
  "Write-Host ('cmake ' + $src + ' ' + ($args -join ' '));" ^
  "Set-Location $bld;" ^
  "& cmake $src @args;" ^
  "if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE };" ^
  "& cmake --build . --config Release;" ^
  "if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE };" ^
  "& cmake --install . --config Release;" ^
  "if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }"

if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Build failed.
    exit /b 1
)

echo.
echo ========================================
echo  Build successful!
echo  Toolchain  : %VS_GENERATOR%
echo  JAVA_HOME  : %JAVA_HOME%
echo  JNI DLLs   : %INSTALL_DIR%\bin
echo  JAR file   : %INSTALL_DIR%\lib\java\ctpmini-java.jar
echo  Java source: %INSTALL_DIR%\java\src
echo ========================================
endlocal
