cmake_minimum_required(VERSION 3.15)

project(GazeboExample VERSION 0.1.0 LANGUAGES CXX)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS}
                    ${PROJECT_SOURCE_DIR}/include)
link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")


add_library(model_info SHARED include/ModelInfo.h 
                              src/ModelInfo.cpp)
target_link_libraries(model_info ${GAZEBO_LIBRARIES})

add_library(world_gravity SHARED include/WorldGravity.h
                                 src/WorldGravity.cpp)
target_link_libraries(world_gravity ${GAZEBO_LIBRARIES})

