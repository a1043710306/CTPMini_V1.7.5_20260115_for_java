cmake_minimum_required(VERSION 3.14)
project(ctpjni VERSION 1.7.5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ─────────────────────────────────────────────────────────────
# MSVC 全局编译选项：处理 CTP SDK 头文件 GBK 编码问题
# ─────────────────────────────────────────────────────────────
if(MSVC)
    add_compile_options("/utf-8")   # 源文件与执行字符集均为 UTF-8
    add_compile_options("/wd4828")  # 抑制"文件包含非 UTF-8 字符"警告（CTP SDK 头文件为 GBK）
endif()

# ═══════════════════════════════════════════════════════════════
#  CTP Mini JNI 桥接库 - 统一构建脚本（Windows / Linux）
#
#  目录层级：
#    <root>/
#    ├── CTPMini_V1.7.5_win_api_20260115/      (Windows SDK)
#    │   ├── win64/traderapi/
#    │   └── win64/mdapi/
#    ├── CTPMini_V1.7.5_linux64_api_20260115/  (Linux SDK)
#    │   ├── traderapi/
#    │   └── mdapi/
#    └── ctpjava/
#        └── jni/   ← CMAKE_CURRENT_SOURCE_DIR（本文件所在）
#
#  Windows 用法（x64）：
#    cd ctpjava\jni
#    cmake -S . -B build_win64 -G "Visual Studio 17 2022" -A x64
#    cmake --build build_win64 --config Release
#
#  Windows 用法（x86）：
#    cmake -S . -B build_win32 -G "Visual Studio 17 2022" -A Win32
#    cmake --build build_win32 --config Release
#
#  Linux 用法：
#    cd ctpjava/jni
#    cmake -S . -B build_linux -DCMAKE_BUILD_TYPE=Release
#    cmake --build build_linux -- -j$(nproc)
# ═══════════════════════════════════════════════════════════════

# ─────────────────────────────────────────────────────────────
# 公共：CTP SDK 根目录（jni/ 上跳两级到项目根）
# ─────────────────────────────────────────────────────────────
set(_CTP_ROOT_REL "${CMAKE_CURRENT_SOURCE_DIR}/../..")
get_filename_component(CTP_ROOT "${_CTP_ROOT_REL}" ABSOLUTE)

# ─────────────────────────────────────────────────────────────
# 平台分支
# ─────────────────────────────────────────────────────────────
if(WIN32)
    # ── Windows ──────────────────────────────────────────────
    set(CTP_SDK_ROOT "${CTP_ROOT}/CTPMini_V1.7.5_win_api_20260115")

    # 根据指针大小自动选择 win64 / win32
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CTP_ARCH "win64")
    else()
        set(CTP_ARCH "win32")
    endif()

    set(CTP_TRADER_DIR "${CTP_SDK_ROOT}/${CTP_ARCH}/traderapi")
    set(CTP_MD_DIR     "${CTP_SDK_ROOT}/${CTP_ARCH}/mdapi")

    # 验证关键文件
    if(NOT EXISTS "${CTP_TRADER_DIR}/thosttraderapi.lib")
        message(FATAL_ERROR
            "找不到: ${CTP_TRADER_DIR}/thosttraderapi.lib\n"
            "请确认 CTPMini_V1.7.5_win_api_20260115 与 ctpjava/ 位于同一父目录下")
    endif()
    if(NOT EXISTS "${CTP_MD_DIR}/thostmduserapi.lib")
        message(FATAL_ERROR "找不到: ${CTP_MD_DIR}/thostmduserapi.lib")
    endif()

    message(STATUS "[ctpjni] 平台   : Windows ${CTP_ARCH}")

else()
    # ── Linux ─────────────────────────────────────────────────
    set(CTP_SDK_ROOT "${CTP_ROOT}/CTPMini_V1.7.5_linux64_api_20260115")

    set(CTP_TRADER_DIR "${CTP_SDK_ROOT}/traderapi")
    set(CTP_MD_DIR     "${CTP_SDK_ROOT}/mdapi")

    # 验证关键文件
    if(NOT EXISTS "${CTP_TRADER_DIR}/libthosttraderapi.so")
        message(FATAL_ERROR
            "找不到: ${CTP_TRADER_DIR}/libthosttraderapi.so\n"
            "请确认 CTPMini_V1.7.5_linux64_api_20260115 与 ctpjava/ 位于同一父目录下")
    endif()
    if(NOT EXISTS "${CTP_MD_DIR}/libthostmduserapi.so")
        message(FATAL_ERROR "找不到: ${CTP_MD_DIR}/libthostmduserapi.so")
    endif()

    message(STATUS "[ctpjni] 平台   : Linux x64")
endif()

message(STATUS "[ctpjni] CTP SDK: ${CTP_SDK_ROOT}")
message(STATUS "[ctpjni] Trader  : ${CTP_TRADER_DIR}")
message(STATUS "[ctpjni] Md      : ${CTP_MD_DIR}")

# ─────────────────────────────────────────────────────────────
# JNI 头文件
# ─────────────────────────────────────────────────────────────
find_package(JNI REQUIRED)
message(STATUS "[ctpjni] JNI    : ${JNI_INCLUDE_DIRS}")

# ─────────────────────────────────────────────────────────────
# 源文件
# ─────────────────────────────────────────────────────────────
set(SOURCES
    src/jni_utils.cpp
    src/struct_convert.cpp
    src/MdApi_jni.cpp
    src/TraderApi_jni.cpp
)

# ─────────────────────────────────────────────────────────────
# 共享库目标
# ─────────────────────────────────────────────────────────────
add_library(ctpjni SHARED ${SOURCES})

if(WIN32)
    # Windows: 输出 ctpjni.dll（无 lib 前缀）
    set_target_properties(ctpjni PROPERTIES OUTPUT_NAME "ctpjni" PREFIX "")
else()
    # Linux: 输出 libctpjni.so
    set_target_properties(ctpjni PROPERTIES OUTPUT_NAME "ctpjni" PREFIX "lib")
endif()

# ─────────────────────────────────────────────────────────────
# 编译选项（平台分支）
# ─────────────────────────────────────────────────────────────
if(WIN32)
    target_compile_definitions(ctpjni PRIVATE
        WIN32_LEAN_AND_MEAN
        NOMINMAX
        _CRT_SECURE_NO_WARNINGS
        WINDOWS
    )
    target_compile_options(ctpjni PRIVATE
        /W3     # 警告级别
        /MP     # 多处理器并行编译
    )
else()
    target_compile_options(ctpjni PRIVATE
        -Wall
        -fvisibility=hidden
    )
endif()

# ─────────────────────────────────────────────────────────────
# 头文件搜索路径
# ─────────────────────────────────────────────────────────────
target_include_directories(ctpjni PRIVATE
    ${JNI_INCLUDE_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CTP_TRADER_DIR}"
    "${CTP_MD_DIR}"
)

# ─────────────────────────────────────────────────────────────
# 链接库（平台分支）
# ─────────────────────────────────────────────────────────────
if(WIN32)
    target_link_libraries(ctpjni PRIVATE
        "${CTP_TRADER_DIR}/thosttraderapi.lib"
        "${CTP_MD_DIR}/thostmduserapi.lib"
    )
else()
    target_link_libraries(ctpjni PRIVATE
        "${CTP_TRADER_DIR}/libthosttraderapi.so"
        "${CTP_MD_DIR}/libthostmduserapi.so"
        dl
        pthread
    )
endif()

# ─────────────────────────────────────────────────────────────
# Windows POST_BUILD：自动复制 CTP DLL 到输出目录
# ─────────────────────────────────────────────────────────────
if(WIN32)
    add_custom_command(TARGET ctpjni POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CTP_TRADER_DIR}/thosttraderapi.dll"
            "$<TARGET_FILE_DIR:ctpjni>/thosttraderapi.dll"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CTP_MD_DIR}/thostmduserapi.dll"
            "$<TARGET_FILE_DIR:ctpjni>/thostmduserapi.dll"
        COMMENT "[ctpjni] 复制 CTP DLL 到输出目录"
    )
endif()

# ─────────────────────────────────────────────────────────────
# 安装规则
# ─────────────────────────────────────────────────────────────
if(WIN32)
    install(TARGETS ctpjni RUNTIME DESTINATION bin ARCHIVE DESTINATION lib)
    install(FILES
        "${CTP_TRADER_DIR}/thosttraderapi.dll"
        "${CTP_MD_DIR}/thostmduserapi.dll"
        DESTINATION bin
    )
else()
    install(TARGETS ctpjni DESTINATION lib)
    install(FILES
        "${CTP_TRADER_DIR}/libthosttraderapi.so"
        "${CTP_MD_DIR}/libthostmduserapi.so"
        DESTINATION lib
    )
endif()

# ─────────────────────────────────────────────────────────────
# 摘要
# ─────────────────────────────────────────────────────────────
if(WIN32)
    message(STATUS "[ctpjni] 输出   : ctpjni.dll")
else()
    message(STATUS "[ctpjni] 输出   : libctpjni.so")
endif()
