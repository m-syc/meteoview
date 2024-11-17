# Use the official GCC image from Docker Hub
FROM gcc:12.4.0

# Define a build argument to accept the path
ARG PROJECT_PATH

# Install necessary tools: CMake, Python (for Conan), and Conan
RUN apt-get update && apt-get install -y \
    cmake \
    python3-pip \
    python3-venv \
    pipx \
    gdb \
    make \
    && pipx install conan \
    && apt-get clean

# Add pipx-installed executables to PATH
ENV PATH="/root/.local/bin:$PATH"

# Set the working directory inside the container
WORKDIR ${PROJECT_PATH}

# Ensure Conan profile is created, then modify it
RUN conan profile detect || true \
    && test -f ~/.conan2/profiles/default && sed -i 's|^settings.compiler.libcxx=.*|settings.compiler.libcxx=libstdc++11|' ~/.conan2/profiles/default \
    && echo "settings.build_type=Debug" >> ~/.conan2/profiles/default || echo "Conan profile not found, skipping sed commands"

CMD ["/bin/bash"]

# docker build -t cpp_gcc_env --build-arg PROJECT_PATH=$(pwd) .
# ./start_docker
# ./configure
# ./build
