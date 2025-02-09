cmake_minimum_required(VERSION 3.31)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(GLFW_BUILD_WAYLAND ON CACHE BOOL "" FORCE)

project(raylib_test LANGUAGES C)

include(FetchContent)

set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
  )

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

set(SOURCE_FILES src/main.c )

add_executable(raylib_test ${SOURCE_FILES})

target_link_libraries(raylib_test raylib)

