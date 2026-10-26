cmake_minimum_required (VERSION 3.20)
cmake_policy(SET CMP0048 NEW)

set(FULL_PROJECT_NAME
    meteoview
)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(MAIN_SOURCE
    src/main.cpp
)

project(${FULL_PROJECT_NAME} VERSION 1.0.0)
add_executable(${PROJECT_NAME} ${MAIN_SOURCE})
target_include_directories(${PROJECT_NAME} INTERFACE src)

add_subdirectory("libs/ContentProvider")
add_subdirectory("libs/ConfigCore")
add_subdirectory("libs/ImageManager")
find_package(fmt REQUIRED)
find_package(GIF REQUIRED)

target_link_libraries(${FULL_PROJECT_NAME} fmt::fmt GIF::GIF)
target_link_libraries(${FULL_PROJECT_NAME} ContentProvider ConfigCore ImageManager)
