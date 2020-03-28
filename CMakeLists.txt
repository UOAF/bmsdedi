# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

INCLUDE_DIRECTORIES(
    src/main
    src/wrapper
)

project (d3d9)
set(SOURCES
    src/main/dllmain.cpp
    src/wrapper/IDirect3D9Ex.cpp
    src/wrapper/IDirect3DCubeTexture9.cpp
    src/wrapper/IDirect3DDevice9Ex.cpp
    src/wrapper/IDirect3DIndexBuffer9.cpp
    src/wrapper/IDirect3DPixelShader9.cpp
    src/wrapper/IDirect3DQuery9.cpp
    src/wrapper/IDirect3DStateBlock9.cpp
    src/wrapper/IDirect3DSurface9.cpp
    src/wrapper/IDirect3DSwapChain9.cpp
    src/wrapper/IDirect3DTexture9.cpp
    src/wrapper/IDirect3DVertexBuffer9.cpp
    src/wrapper/IDirect3DVertexDeclaration9.cpp
    src/wrapper/IDirect3DVertexShader9.cpp
    src/wrapper/IDirect3DVolume9.cpp
    src/wrapper/IDirect3DVolumeTexture9.cpp
    src/wrapper/InterfaceQuery.cpp
    src/wrapper/d3d9.def
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++17 -Wno-microsoft-exception-spec -Wno-deprecated-declarations")

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_library(d3d9 SHARED ${SOURCES})

