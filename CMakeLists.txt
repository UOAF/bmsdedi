# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.8)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_STANDARD 17)

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
    add_compile_options("/W4" "/Za" "$<$<CONFIG:RELEASE>:/O2>")
else()
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g")
    string(CONCAT CMAKE_CXX_FLAGS
        "-Wall -Wextra "
        "-Wno-deprecated-declarations "
        "-Wno-microsoft-exception-spec "
        # Cargo culted from default CMAKE flags, see
        # https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-160
        "-D_DLL=1 -D_MT=1"
    )
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
target_link_libraries(d3d11 "-lmsvcrt")
