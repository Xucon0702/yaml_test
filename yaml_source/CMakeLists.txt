cmake_minimum_required(VERSION 3.10)

project(yaml-cpp)

set(PROJECT_YAML_SOURCE_DIR ${PROJECT_SOURCE_DIR}/yaml_source)

message("333:${PROJECT_YAML_SOURCE_DIR}")

include_directories(
    ${PROJECT_YAML_SOURCE_DIR}/
    ${PROJECT_YAML_SOURCE_DIR}/contrub
       
)

file(GLOB_RECURSE YAML_SOURCE_FILES 
${PROJECT_YAML_SOURCE_DIR}/  *.c *.cpp
)

# add_library(yaml-cpp ${YAML_SOURCE_FILES})

# 同时生成静态库和动态库;注意动态库要放在后面
ADD_LIBRARY(yaml-cpp_static STATIC ${YAML_SOURCE_FILES})  #STATIC
set_target_properties(yaml-cpp_static PROPERTIES OUTPUT_NAME "yaml-cpp")

add_library(yaml-cpp SHARED ${YAML_SOURCE_FILES})  #SHARED