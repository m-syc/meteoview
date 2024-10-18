# Use the official GCC image from Docker Hub
FROM gcc:11.3.0

# Install necessary tools: CMake, Python (for Conan), and Conan
RUN apt-get update && apt-get install -y \
    cmake \
    python3-pip \
    && pip3 install conan \
    && apt-get clean

# Set the working directory inside the container
WORKDIR /project

# Set up Conan profile (relative to the container's /project folder)
RUN conan profile detect || true

# Modify the Conan profile to use libstdc++11
RUN sed -i 's|libstdc++$|libstdc++11|' ~/.conan2/profiles/default

CMD ["/bin/bash"]
