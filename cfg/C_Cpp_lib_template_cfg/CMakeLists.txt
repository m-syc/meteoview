

cmake_minimum_required (VERSION 3.8)
cmake_policy(SET CMP0048 NEW)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

set(headers
    lib_cfg.h)

add_library(C_Cpp_lib_template_cfg STATIC ${headers})
set_target_properties(C_Cpp_lib_template_cfg PROPERTIES LINKER_LANGUAGE C)
target_include_directories(C_Cpp_lib_template_cfg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})