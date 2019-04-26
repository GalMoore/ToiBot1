cmake_minimum_required(VERSION 2.8.3)
project(purim_imgs)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)




find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  image_transport
  roscpp
  dynamic_reconfigure
  std_msgs
  cv_bridge
  message_generation

)

find_package(OpenCV REQUIRED)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}


)



catkin_package()



add_executable(purim_imgs_node
    src/main.cpp


  )

  add_dependencies(purim_imgs_node
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
  )

  target_link_libraries(purim_imgs_node
    ${catkin_LIBRARIES}
    ${OpenCV_LIBRARIES}

  )
