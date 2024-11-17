#!/bin/bash

# Get the directory where the script is located (relative to the script itself)
SCRIPT_DIR="$(dirname "$0")"
# PROJECT_DIR="$SCRIPT_DIR"
PROJECT_DIR="$(pwd)"
CONAN_CACHE_DIR="$PROJECT_DIR/conan_cache"  # Local directory to store the conan cache from the container

CONTAINER_NAME=cpp_gcc_container

# Create a local conan_cache directory if it doesn't exist
mkdir -p $CONAN_CACHE_DIR

# Check if the container is already running
if [ "$(docker ps -q -f name=$CONTAINER_NAME)" ]; then
    echo "Container $CONTAINER_NAME is already running."
else
    # Check if the container exists (but not running)
    if [ "$(docker ps -aq -f status=exited -f name=$CONTAINER_NAME)" ]; then
        echo "Starting existing container $CONTAINER_NAME..."
        docker start $CONTAINER_NAME
    else
        echo $CONAN_CACHE_DIR
        # If the container doesn't exist, create and start it
        echo "Creating and starting new container $CONTAINER_NAME..."
        docker run -d \
            --name $CONTAINER_NAME \
            -e BUILD_TYPE=${BUILD_TYPE:-Debug} \
            -v $PROJECT_DIR:${PROJECT_DIR} \
            -v $CONAN_CACHE_DIR:/root/.conan2 \
            -w ${PROJECT_DIR} \
            cpp_gcc_env tail -f /dev/null
    fi
fi
