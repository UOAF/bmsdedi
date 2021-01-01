# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.8)

INCLUDE_DIRECTORIES(
    src/main
    src/d3d11
    src
)

project (d3d11)
set(SOURCES
    src/main/gui.cpp
    src/main/dllmain.cpp
    src/d3d11/d3d11.cpp
    src/d3d11/exports.def
    src/d3d11/exports_.cpp
    src/d3d11/D3D11DeviceContextWrapper.cpp
)

if(MSVC)
    add_compile_options("/W4" "/std:c++17" "/Za" "$<$<CONFIG:RELEASE>:/O2>")
else()
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
    add_compile_options("-Wall" "$<$<CONFIG:RELEASE>:-O3>")
    add_compile_options("-std=c++17" "-Wno-deprecated-declarations")
    add_compile_options("-Wno-microsoft-exception-spec")
    # if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    #     add_compile_options("-stdlib=libc++")
    # else()
    #     # nothing special for gcc at the moment
    # endif()
endif()


# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_library(d3d11 SHARED ${SOURCES})

