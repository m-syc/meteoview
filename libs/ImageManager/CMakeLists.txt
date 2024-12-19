cmake_minimum_required(VERSION 3.18)
cmake_policy(SET CMP0048 NEW)
set(LIB_NAME
    ImageManager
)

# Add this to the top of your CMakeLists.txt
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}" ${CMAKE_PREFIX_PATH})

project(
    ${LIB_NAME}
    VERSION 0.0.0
    DESCRIPTION "What does it do?"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES ImageObj.hpp src/ImageObj.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ./)
