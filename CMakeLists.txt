cmake_minimum_required(VERSION 2.8.3)
project(vOdom)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++14 -O3")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  laser_geometry
  sensor_msgs
  geometry_msgs
  nav_msgs
  rosbag
  cv_bridge
)

find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)
find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(OpenCV REQUIRED)

catkin_package(
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp cv_bridge 
  DEPENDS PCL OpenCV 
  INCLUDE_DIRS include
  LIBRARIES 
)

include_directories(
  "/usr/include/eigen3"
  src
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

add_executable(vOdom
  src/main.cpp
)

target_link_libraries(vOdom
  ${catkin_LIBRARIES}
  ${PCL_LIBRARIES}
  ${OpenCV_LIBS}
  ${Boost_LIBRARIES}
)

install(TARGETS vOdom
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)