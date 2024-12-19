cmake_minimum_required(VERSION 3.18)
cmake_policy(SET CMP0048 NEW)
set(LIB_NAME
    ConfigCore
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

set(SOURCES CfgReader.hpp src/CfgReader.cpp
            BasicCfg.hpp src/BasicCfg.cpp
            ChmiCfg.hpp src/ChmiCfg.cpp
            ModellzentraleCfg.hpp src/ModellzentraleCfg.cpp
            Sat24Cfg.hpp src/Sat24Cfg.cpp
            MeteoService.hpp src/MeteoService.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(${PROJECT_NAME} ${SOURCES})

find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
target_link_libraries(${PROJECT_NAME} fmt::fmt nlohmann_json::nlohmann_json)
target_include_directories(${PROJECT_NAME} PUBLIC ./)
