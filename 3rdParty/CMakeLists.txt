project(Deps VERSION 0.1 LANGUAGES C CXX)

# Detours lib
add_library(Detours
    Detours/src/detours.cpp
    Detours/src/disasm.cpp
    )

target_compile_definitions(Detours PRIVATE "DETOURS_X86" "DETOURS_32BIT")

target_include_directories(Detours PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Detours/src>
    $<INSTALL_INTERFACE:Detours/src>)

set_property(TARGET Detours PROPERTY FOLDER "3rdParty")
export(TARGETS Detours FILE Detours.cmake)

# EasyLogging++ lib
add_library(EasyLogging++
    EasyLogging++/EasyLogging/src/easylogging++.cc
    EasyLogging++/EasyLogging/src/easylogging++.h
    )

target_include_directories(EasyLogging++ PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/EasyLogging++/EasyLogging/src>
    $<INSTALL_INTERFACE:EasyLogging++/EasyLogging/src>)

set_property(TARGET EasyLogging++ PROPERTY FOLDER "3rdParty")
export(TARGETS EasyLogging++ FILE EasyLogging++.cmake)

# DxOld lib
add_library(DxOld INTERFACE)
target_include_directories(DxOld INTERFACE DxOld/)
export(TARGETS DxOld FILE DxOld.cmake)

# gmock/gtest lib
add_library(gmock
    gmock-1.7.0/src/gmock-all.cc
    gmock-1.7.0/gtest/src/gtest-all.cc
    )

target_include_directories(gmock PUBLIC
    $<BUILD_INTERFACE:
    ${CMAKE_CURRENT_SOURCE_DIR}/gmock-1.7.0/include;
    ${CMAKE_CURRENT_SOURCE_DIR}/gmock-1.7.0;
    ${CMAKE_CURRENT_SOURCE_DIR}/gmock-1.7.0/include/internal;
    ${CMAKE_CURRENT_SOURCE_DIR}/gmock-1.7.0/gtest;
    ${CMAKE_CURRENT_SOURCE_DIR}/gmock-1.7.0/gtest/include;
    ${CMAKE_CURRENT_SOURCE_DIR}/gmock-1.7.0/gtest/include/gtest/internal>
    $<INSTALL_INTERFACE:gmock/include>
    )

export(TARGETS gmock FILE gmock.cmake)
set_property(TARGET gmock PROPERTY FOLDER "3rdParty")

# zlib
add_library(zlib
    zlib-old-1.1.3/trees.c
    zlib-old-1.1.3/adler32.c
    zlib-old-1.1.3/inffast.c
    zlib-old-1.1.3/infcodes.c
    zlib-old-1.1.3/infutil.c
    zlib-old-1.1.3/crc32.c
    zlib-old-1.1.3/zutil.c
    zlib-old-1.1.3/infblock.c
    zlib-old-1.1.3/inftrees.c
    zlib-old-1.1.3/inflate.c
    zlib-old-1.1.3/deflate.c
    zlib-old-1.1.3/deflate.h
    )

target_include_directories(zlib PUBLIC
    $<BUILD_INTERFACE:
    ${CMAKE_CURRENT_SOURCE_DIR}/zlib-old-1.1.3;
    $<INSTALL_INTERFACE:zlib/include>
    )

export(TARGETS zlib FILE zlib.cmake)
set_property(TARGET zlib PROPERTY FOLDER "3rdParty")
