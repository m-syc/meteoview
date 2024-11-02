#!/bin/bash

# Get the directory where the script is located (relative to the script itself)
SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR"
BUILD_DIR="$PROJECT_DIR/build"

CONTAINER_NAME=cpp_gcc_container

# Build the project
docker exec -it $CONTAINER_NAME bash -c "cmake --build $BUILD_DIR"
