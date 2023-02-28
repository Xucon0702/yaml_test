cmake_minimum_required(VERSION 3.10)

project(yaml-test)

message(${PROJECT_SOURCE_DIR})

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/yaml-cpp
    # # ${PROJECT_SOURCE_DIR}/include/yaml-cpp/contrub
    # # ${PROJECT_SOURCE_DIR}/include/yaml-cpp/node
    ${PROJECT_SOURCE_DIR}/src 
    ${PROJECT_SOURCE_DIR}/src/config_yaml_func/
    ${PROJECT_SOURCE_DIR}/src/config_vehicle/

       
)

message("111:${PROJECT_SOURCE_DIR}/include")


link_directories(
    ${PROJECT_SOURCE_DIR}/lib
)

message("222:${PROJECT_SOURCE_DIR}/lib")

file(GLOB SOURCE_FILES 
    ${PROJECT_SOURCE_DIR}/src/*.c 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/config_yaml_func/*.cpp
    ${PROJECT_SOURCE_DIR}/src/config_vehicle/*.cpp
 )

# add_subdirectory(yaml_source)  #编译yaml_cpp库时打开

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        yaml-cpp
  )

message("project name:${PROJECT_NAME}")

#目标文件存储位置
install(TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/install/bin)