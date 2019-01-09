cmake_minimum_required(VERSION 2.8.3)
project(coordination_publisher)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
)

## Generate messages in the 'msg' folder
add_message_files(FILES
  coordination.msg
)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(DEPENDENCIES
  std_msgs
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
CATKIN_DEPENDS
   roscpp
)

###########
## Build ##
###########

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/coordination_publisher.cpp
# )



add_executable(coordination_node_pub
  src/coordination_node_pub.cpp
)
add_dependencies(coordination_node_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(coordination_node_pub
  ${catkin_LIBRARIES}
)

add_executable(coordination_node_sub
  src/coordination_node_sub.cpp
)
add_dependencies(coordination_node_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(coordination_node_sub
  ${catkin_LIBRARIES}
)