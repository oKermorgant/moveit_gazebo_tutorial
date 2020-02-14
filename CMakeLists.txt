cmake_minimum_required(VERSION 2.8.3)
project(moveit_gazebo_tutorial)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  )

catkin_package()

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(pc_convert pc_convert.cpp)
target_include_directories(pc_convert PRIVATE ${catkin_INCLUDE_DIRS})
target_link_libraries(pc_convert ${catkin_LIBRARIES})
