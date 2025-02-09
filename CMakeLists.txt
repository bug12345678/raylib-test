cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(GLFW_BUILD_WAYLAND ON CACHE BOOL "" FORCE)

project(raylib_test LANGUAGES C)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

set(SOURCE_FILES src/main.c )

add_executable(raylib_test ${SOURCE_FILES})

target_link_libraries(raylib_test raylib)