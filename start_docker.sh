#!/bin/bash

# Get the directory where the script is located (relative to the script itself)
SCRIPT_DIR="$(dirname "$0")"
PROJECT_DIR="$SCRIPT_DIR"

CONTAINER_NAME=cpp_gcc_container

# Check if the container is already running
if [ "$(docker ps -q -f name=$CONTAINER_NAME)" ]; then
    echo "Container $CONTAINER_NAME is already running."
else
    # Check if the container exists (but not running)
    if [ "$(docker ps -aq -f status=exited -f name=$CONTAINER_NAME)" ]; then
        echo "Starting existing container $CONTAINER_NAME..."
        docker start $CONTAINER_NAME
    else
        # If the container doesn't exist, create and start it
        echo "Creating and starting new container $CONTAINER_NAME..."
        docker run -d \
            --name $CONTAINER_NAME \
            -v $PROJECT_DIR:/project \
            -w /project \
            cpp_gcc_env tail -f /dev/null
    fi
fi
