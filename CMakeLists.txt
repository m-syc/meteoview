cmake_minimum_required (VERSION 3.8)
cmake_policy(SET CMP0048 NEW)

set(TEMP_PROJECT_NAME
    C_Cpp-template
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCE_DIR
    src
)

set(MAIN_SOURCE
    src/main.cpp
)

# Fill with all library config names used in project
set(TEMP_CFGS
    C_Cpp_lib_template_cfg
)

# Fill with library names used in project. Libraries may be git submodules or standalone.
set(TEMP_LIBRARIES
    C_Cpp_lib_template
)

project(${TEMP_PROJECT_NAME} VERSION 1.0.0)
add_executable(${PROJECT_NAME} ${MAIN_SOURCE})
target_include_directories(${PROJECT_NAME} INTERFACE src)

foreach(LIBRARY ${TEMP_LIBRARIES})
    add_subdirectory("libs/${LIBRARY}")
    target_link_libraries(${TEMP_PROJECT_NAME} PUBLIC ${LIBRARY})
endforeach(LIBRARY)

foreach(CFG ${TEMP_CFGS})
    add_subdirectory("cfg/${CFG}")
    target_include_directories(${TEMP_PROJECT_NAME} PRIVATE "cfg/${CFG}")
endforeach(CFG)
