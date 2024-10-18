#!/bin/bash

# Get the directory where the script is located (relative to the script itself)
SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR"
BUILD_DIR="$PROJECT_DIR/build"

CONTAINER_NAME=cpp_gcc_container

# Install Conan dependencies into the build directory (relative to the script)
docker exec -it $CONTAINER_NAME bash -c "conan install $PROJECT_DIR --build=missing -of=$BUILD_DIR"

# Run CMake configuration and build, using relative paths
docker exec -it $CONTAINER_NAME bash -c "cmake -S $PROJECT_DIR -B $BUILD_DIR -DCMAKE_TOOLCHAIN_FILE=$BUILD_DIR/conan_toolchain.cmake -DCMAKE_PREFIX_PATH=$BUILD_DIR -DCMAKE_BUILD_TYPE=Release"

# Build the project
docker exec -it $CONTAINER_NAME bash -c "cmake --build $BUILD_DIR"
