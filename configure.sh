#!/bin/bash

# Get the directory where the script is located (relative to the script itself)
SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR"
BUILD_DIR="$PROJECT_DIR/build"

CONTAINER_NAME=cpp_gcc_container


# Check for BUILD_TYPE or default to Release
BUILD_TYPE="Debug"

docker exec -it $CONTAINER_NAME bash -c "mkdir -p ~/.conan2/profiles && echo '[settings]\narch=x86_64\nbuild_type=Debug\ncompiler=gcc\ncompiler.cppstd=gnu17\ncompiler.libcxx=libstdc++11\ncompiler.version=12\nos=Linux' > ~/.conan2/profiles/debug"

docker exec -it $CONTAINER_NAME bash -c "mkdir -p ~/.conan2/profiles && echo '[settings]\narch=x86_64\nbuild_type=Release\ncompiler=gcc\ncompiler.cppstd=gnu17\ncompiler.libcxx=libstdc++11\ncompiler.version=12\nos=Linux' > ~/.conan2/profiles/release"


# Select the correct profile
PROFILE_NAME="release"
if [ "$BUILD_TYPE" == "Debug" ]; then
    PROFILE_NAME="debug"
fi

# Install Conan dependencies with the chosen profile
docker exec -it $CONTAINER_NAME bash -c "conan install $PROJECT_DIR --build=missing -of=$BUILD_DIR -s arch=x86_64 -s build_type=$BUILD_TYPE -s compiler=gcc -s compiler.version=12 -s compiler.libcxx=libstdc++11 -s compiler.cppstd=gnu17 -s os=Linux"

# Run CMake configuration with Conan toolchain and build type
docker exec -it $CONTAINER_NAME bash -c "cmake -S $PROJECT_DIR -B $BUILD_DIR -DCMAKE_TOOLCHAIN_FILE=$BUILD_DIR/conan_toolchain.cmake -DCMAKE_PREFIX_PATH=$BUILD_DIR -DCMAKE_BUILD_TYPE=$BUILD_TYPE"
