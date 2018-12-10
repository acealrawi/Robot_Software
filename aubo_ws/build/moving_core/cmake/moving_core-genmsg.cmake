# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "moving_core: 1 messages, 1 services")

set(MSG_I_FLAGS "-Imoving_core:/home/ali/Robot_Software/aubo_ws/src/moving_core/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(moving_core_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv" NAME_WE)
add_custom_target(_moving_core_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "moving_core" "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv" "geometry_msgs/Quaternion:geometry_msgs/Pose:geometry_msgs/Point"
)

get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg" NAME_WE)
add_custom_target(_moving_core_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "moving_core" "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg" "geometry_msgs/Quaternion:geometry_msgs/Pose:geometry_msgs/Point"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/moving_core
)

### Generating Services
_generate_srv_cpp(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/moving_core
)

### Generating Module File
_generate_module_cpp(moving_core
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/moving_core
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(moving_core_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(moving_core_generate_messages moving_core_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv" NAME_WE)
add_dependencies(moving_core_generate_messages_cpp _moving_core_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg" NAME_WE)
add_dependencies(moving_core_generate_messages_cpp _moving_core_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(moving_core_gencpp)
add_dependencies(moving_core_gencpp moving_core_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS moving_core_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/moving_core
)

### Generating Services
_generate_srv_eus(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/moving_core
)

### Generating Module File
_generate_module_eus(moving_core
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/moving_core
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(moving_core_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(moving_core_generate_messages moving_core_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv" NAME_WE)
add_dependencies(moving_core_generate_messages_eus _moving_core_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg" NAME_WE)
add_dependencies(moving_core_generate_messages_eus _moving_core_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(moving_core_geneus)
add_dependencies(moving_core_geneus moving_core_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS moving_core_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/moving_core
)

### Generating Services
_generate_srv_lisp(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/moving_core
)

### Generating Module File
_generate_module_lisp(moving_core
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/moving_core
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(moving_core_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(moving_core_generate_messages moving_core_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv" NAME_WE)
add_dependencies(moving_core_generate_messages_lisp _moving_core_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg" NAME_WE)
add_dependencies(moving_core_generate_messages_lisp _moving_core_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(moving_core_genlisp)
add_dependencies(moving_core_genlisp moving_core_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS moving_core_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/moving_core
)

### Generating Services
_generate_srv_nodejs(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/moving_core
)

### Generating Module File
_generate_module_nodejs(moving_core
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/moving_core
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(moving_core_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(moving_core_generate_messages moving_core_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv" NAME_WE)
add_dependencies(moving_core_generate_messages_nodejs _moving_core_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg" NAME_WE)
add_dependencies(moving_core_generate_messages_nodejs _moving_core_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(moving_core_gennodejs)
add_dependencies(moving_core_gennodejs moving_core_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS moving_core_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/moving_core
)

### Generating Services
_generate_srv_py(moving_core
  "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/moving_core
)

### Generating Module File
_generate_module_py(moving_core
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/moving_core
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(moving_core_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(moving_core_generate_messages moving_core_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/srv/LocalizePart.srv" NAME_WE)
add_dependencies(moving_core_generate_messages_py _moving_core_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ali/Robot_Software/aubo_ws/src/moving_core/msg/PoseMessage.msg" NAME_WE)
add_dependencies(moving_core_generate_messages_py _moving_core_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(moving_core_genpy)
add_dependencies(moving_core_genpy moving_core_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS moving_core_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/moving_core)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/moving_core
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(moving_core_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(moving_core_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/moving_core)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/moving_core
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(moving_core_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(moving_core_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/moving_core)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/moving_core
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(moving_core_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(moving_core_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/moving_core)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/moving_core
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(moving_core_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(moving_core_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/moving_core)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/moving_core\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/moving_core
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(moving_core_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(moving_core_generate_messages_py geometry_msgs_generate_messages_py)
endif()
