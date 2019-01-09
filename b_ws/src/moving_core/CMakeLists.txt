cmake_minimum_required(VERSION 2.8.3)
project(moving_core)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roslib
  descartes_core
  descartes_moveit
  descartes_trajectory
  descartes_planner
  descartes_utilities
  trajectory_msgs
  ar_publisher
  geometry_msgs
  message_generation
  tf
  tf_conversions
  moveit_ros_planning_interface
)

add_message_files(FILES
  PoseMessage.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  # PlanCartesianPath.srv
  LocalizePart.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs  # Or other packages containing msgs
)

catkin_package(
   CATKIN_DEPENDS
    roscpp
    ar_publisher
    message_runtime
    geometry_msgs
    tf
    moveit_ros_planning_interface
    ur5_demo_descartes
    descartes_trajectory
    descartes_planner
    descartes_utilities
    trajectory_msgs
)

###########
## Build ##
###########



include_directories(
  ${catkin_INCLUDE_DIRS}
)


# move
add_executable(${PROJECT_NAME}_move src/descartes_move.cpp)
add_executable(vision_node src/vision_node.cpp)
add_executable(moving_node src/moving_node.cpp)

add_dependencies(vision_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(moving_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


target_link_libraries(${PROJECT_NAME}_move ${catkin_LIBRARIES})
target_link_libraries(vision_node ${catkin_LIBRARIES})
target_link_libraries(moving_node ${catkin_LIBRARIES})

set_target_properties(${PROJECT_NAME}_move
  PROPERTIES OUTPUT_NAME move
  PREFIX "")





#############
## Install ##
#############

install(TARGETS ${PROJECT_NAME}_move
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)
