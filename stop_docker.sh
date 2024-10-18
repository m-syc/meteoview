#!/bin/bash

CONTAINER_NAME=cpp_gcc_container

echo "Stopping container $CONTAINER_NAME..."
docker stop $CONTAINER_NAME
