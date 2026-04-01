cmake_minimum_required(VERSION 3.14)
project(CTPMiniJava VERSION 1.7.5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================
# Options
# ============================================================
option(BUILD_MD_API    "Build Market Data API JNI library"  ON)
option(BUILD_TRADE_API "Build Trader API JNI library"       ON)
option(BUILD_JAVA_JAR  "Build generated Java sources to JAR" OFF)

# ============================================================
# Find SWIG (>= 3.0)
# ============================================================
find_package(SWIG 3.0 REQUIRED)
include(${SWIG_USE_FILE})

# ============================================================
# Find Java and JNI
# ============================================================
find_package(Java REQUIRED)
find_package(JNI  REQUIRED)
include(UseJava)

message(STATUS "Java found:  ${Java_JAVA_EXECUTABLE}")
message(STATUS "JNI headers: ${JNI_INCLUDE_DIRS}")

# ============================================================
# Platform detection – set paths to pre-built CTP SDK libs
# ============================================================
set(CTPMINI_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/..")

if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CTPMINI_MD_LIB_DIR    "${CTPMINI_ROOT}/CTPMini_V1.7.5_win_api_20260115/win64/mdapi")
        set(CTPMINI_TRADE_LIB_DIR "${CTPMINI_ROOT}/CTPMini_V1.7.5_win_api_20260115/win64/traderapi")
        set(CTPMINI_MD_LIB    thostmduserapi)
        set(CTPMINI_TRADE_LIB thosttraderapi)
    else()
        set(CTPMINI_MD_LIB_DIR    "${CTPMINI_ROOT}/CTPMini_V1.7.5_win_api_20260115/win32/mdapi")
        set(CTPMINI_TRADE_LIB_DIR "${CTPMINI_ROOT}/CTPMini_V1.7.5_win_api_20260115/win32/traderapi")
        set(CTPMINI_MD_LIB    thostmduserapi)
        set(CTPMINI_TRADE_LIB thosttraderapi)
    endif()
elseif(UNIX)
    set(CTPMINI_MD_LIB_DIR    "${CTPMINI_ROOT}/CTPMini_V1.7.5_linux64_api_20260115/mdapi")
    set(CTPMINI_TRADE_LIB_DIR "${CTPMINI_ROOT}/CTPMini_V1.7.5_linux64_api_20260115/traderapi")
    set(CTPMINI_MD_LIB    thostmduserapi)
    set(CTPMINI_TRADE_LIB thosttraderapi)
endif()

# ============================================================
# Java output directory for generated .java files
# ============================================================
set(JAVA_GEN_DIR "${CMAKE_CURRENT_BINARY_DIR}/java")
file(MAKE_DIRECTORY "${JAVA_GEN_DIR}/mdapi")
file(MAKE_DIRECTORY "${JAVA_GEN_DIR}/tradeapi")

# ============================================================
# Market Data API – libCTPMiniMdApi
# ============================================================
if(BUILD_MD_API)
    set(CMAKE_SWIG_OUTDIR "${JAVA_GEN_DIR}/mdapi")
    set(SWIG_MD_SRC "${CMAKE_CURRENT_SOURCE_DIR}/ThostFtdcMdApi.i")
    set_source_files_properties(${SWIG_MD_SRC} PROPERTIES
        CPLUSPLUS ON
        SWIG_FLAGS "-I${CTPMINI_MD_LIB_DIR};-I${CMAKE_CURRENT_SOURCE_DIR};-package;com.ctpmini.mdapi"
    )

    swig_add_library(CTPMiniMdApi
        TYPE        SHARED
        LANGUAGE    java
        SOURCES     ${SWIG_MD_SRC}
    )

    # Include directories for this target
    target_include_directories(CTPMiniMdApi PRIVATE
        ${JNI_INCLUDE_DIRS}
        ${CTPMINI_MD_LIB_DIR}
    )

    # Link against the CTP pre-built MD library
    find_library(CTPMINI_MD_LIBRARY
        NAMES ${CTPMINI_MD_LIB}
        PATHS ${CTPMINI_MD_LIB_DIR}
        NO_DEFAULT_PATH
    )
    if(NOT CTPMINI_MD_LIBRARY)
        message(FATAL_ERROR "CTP Mini MD library not found in ${CTPMINI_MD_LIB_DIR}")
    endif()
    target_link_libraries(CTPMiniMdApi PRIVATE ${CTPMINI_MD_LIBRARY})

    # Windows: copy the vendor DLL next to the JNI .dll so it is found at runtime
    if(WIN32)
        file(GLOB CTPMINI_MD_RUNTIME_DLLS "${CTPMINI_MD_LIB_DIR}/*.dll")
        foreach(_md_dll ${CTPMINI_MD_RUNTIME_DLLS})
            add_custom_command(TARGET CTPMiniMdApi POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${_md_dll}"
                    "$<TARGET_FILE_DIR:CTPMiniMdApi>"
                COMMENT "Copying MD runtime DLL: ${_md_dll}"
            )
        endforeach()
    endif()

    # Linux: set rpath so the JNI .so can find libthostmduserapi.so at runtime
    if(UNIX)
        set_target_properties(CTPMiniMdApi PROPERTIES
            INSTALL_RPATH "$ORIGIN"
            BUILD_WITH_INSTALL_RPATH TRUE
        )
        file(GLOB CTPMINI_MD_RUNTIME_SOS "${CTPMINI_MD_LIB_DIR}/*.so")
        foreach(_md_so ${CTPMINI_MD_RUNTIME_SOS})
            add_custom_command(TARGET CTPMiniMdApi POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${_md_so}"
                    "$<TARGET_FILE_DIR:CTPMiniMdApi>"
                COMMENT "Copying MD runtime SO: ${_md_so}"
            )
        endforeach()
    endif()
endif()

# ============================================================
# Trader API – libCTPMiniTraderApi
# ============================================================
if(BUILD_TRADE_API)
    set(CMAKE_SWIG_OUTDIR "${JAVA_GEN_DIR}/tradeapi")
    set(SWIG_TRADE_SRC "${CMAKE_CURRENT_SOURCE_DIR}/ThostFtdcTraderApi.i")
    set_source_files_properties(${SWIG_TRADE_SRC} PROPERTIES
        CPLUSPLUS ON
        SWIG_FLAGS "-I${CTPMINI_TRADE_LIB_DIR};-I${CMAKE_CURRENT_SOURCE_DIR};-package;com.ctpmini.tradeapi"
    )

    swig_add_library(CTPMiniTraderApi
        TYPE        SHARED
        LANGUAGE    java
        SOURCES     ${SWIG_TRADE_SRC}
    )

    target_include_directories(CTPMiniTraderApi PRIVATE
        ${JNI_INCLUDE_DIRS}
        ${CTPMINI_TRADE_LIB_DIR}
    )

    find_library(CTPMINI_TRADE_LIBRARY
        NAMES ${CTPMINI_TRADE_LIB}
        PATHS ${CTPMINI_TRADE_LIB_DIR}
        NO_DEFAULT_PATH
    )
    if(NOT CTPMINI_TRADE_LIBRARY)
        message(FATAL_ERROR "CTP Mini Trader library not found in ${CTPMINI_TRADE_LIB_DIR}")
    endif()
    target_link_libraries(CTPMiniTraderApi PRIVATE ${CTPMINI_TRADE_LIBRARY})

    if(WIN32)
        file(GLOB CTPMINI_TRADE_RUNTIME_DLLS "${CTPMINI_TRADE_LIB_DIR}/*.dll")
        foreach(_trade_dll ${CTPMINI_TRADE_RUNTIME_DLLS})
            add_custom_command(TARGET CTPMiniTraderApi POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${_trade_dll}"
                    "$<TARGET_FILE_DIR:CTPMiniTraderApi>"
                COMMENT "Copying Trader runtime DLL: ${_trade_dll}"
            )
        endforeach()
    endif()

    if(UNIX)
        set_target_properties(CTPMiniTraderApi PROPERTIES
            INSTALL_RPATH "$ORIGIN"
            BUILD_WITH_INSTALL_RPATH TRUE
        )
        file(GLOB CTPMINI_TRADE_RUNTIME_SOS "${CTPMINI_TRADE_LIB_DIR}/*.so")
        foreach(_trade_so ${CTPMINI_TRADE_RUNTIME_SOS})
            add_custom_command(TARGET CTPMiniTraderApi POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${_trade_so}"
                    "$<TARGET_FILE_DIR:CTPMiniTraderApi>"
                COMMENT "Copying Trader runtime SO: ${_trade_so}"
            )
        endforeach()
    endif()
endif()

# ============================================================
# Optional: compile generated Java sources into a .jar
# ============================================================
find_program(JAVAC_EXE NAMES javac HINTS ${Java_JAVAC_EXECUTABLE})
if(BUILD_JAVA_JAR AND JAVAC_EXE)
    set(JAR_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/ctpmini-java.jar")
    add_custom_target(ctpmini_jar
        COMMAND ${CMAKE_COMMAND} -E echo "Compiling generated Java sources..."
        COMMAND ${JAVAC_EXE}
            -d "${CMAKE_CURRENT_BINARY_DIR}/classes"
            -sourcepath "${JAVA_GEN_DIR}"
            "${JAVA_GEN_DIR}/mdapi/*.java"
            "${JAVA_GEN_DIR}/tradeapi/*.java"
        COMMAND ${Java_JAR_EXECUTABLE}
            cf "${JAR_OUTPUT}"
            -C "${CMAKE_CURRENT_BINARY_DIR}/classes" .
        COMMENT "Building ctpmini-java.jar"
        DEPENDS CTPMiniMdApi CTPMiniTraderApi
    )
    # Ensure classes output directory exists
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/classes")
    message(STATUS "JAR target: ${JAR_OUTPUT}")
elseif(BUILD_JAVA_JAR AND NOT JAVAC_EXE)
    message(WARNING "BUILD_JAVA_JAR is ON but javac was not found; skipping JAR target")
endif()

# ============================================================
# Install targets
# ============================================================
install(TARGETS CTPMiniMdApi CTPMiniTraderApi
    RUNTIME DESTINATION bin    # .dll on Windows
    LIBRARY DESTINATION lib    # .so on Linux
)

if(WIN32)
    file(GLOB CTPMINI_MD_INSTALL_DLLS "${CTPMINI_MD_LIB_DIR}/*.dll")
    file(GLOB CTPMINI_TRADE_INSTALL_DLLS "${CTPMINI_TRADE_LIB_DIR}/*.dll")
    install(FILES ${CTPMINI_MD_INSTALL_DLLS} ${CTPMINI_TRADE_INSTALL_DLLS} DESTINATION bin)
elseif(UNIX)
    file(GLOB CTPMINI_MD_INSTALL_SOS "${CTPMINI_MD_LIB_DIR}/*.so")
    file(GLOB CTPMINI_TRADE_INSTALL_SOS "${CTPMINI_TRADE_LIB_DIR}/*.so")
    install(FILES ${CTPMINI_MD_INSTALL_SOS} ${CTPMINI_TRADE_INSTALL_SOS} DESTINATION lib)
endif()

install(DIRECTORY "${JAVA_GEN_DIR}/"
    DESTINATION java/src
    FILES_MATCHING PATTERN "*.java"
)
if(BUILD_JAVA_JAR AND JAVAC_EXE)
    install(FILES "${JAR_OUTPUT}" DESTINATION lib/java OPTIONAL)
endif()
