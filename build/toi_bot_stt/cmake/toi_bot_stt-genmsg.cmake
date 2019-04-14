# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "toi_bot_stt: 1 messages, 0 services")

set(MSG_I_FLAGS "-Itoi_bot_stt:/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(toi_bot_stt_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg" NAME_WE)
add_custom_target(_toi_bot_stt_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "toi_bot_stt" "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(toi_bot_stt
  "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/toi_bot_stt
)

### Generating Services

### Generating Module File
_generate_module_cpp(toi_bot_stt
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/toi_bot_stt
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(toi_bot_stt_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(toi_bot_stt_generate_messages toi_bot_stt_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg" NAME_WE)
add_dependencies(toi_bot_stt_generate_messages_cpp _toi_bot_stt_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(toi_bot_stt_gencpp)
add_dependencies(toi_bot_stt_gencpp toi_bot_stt_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS toi_bot_stt_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(toi_bot_stt
  "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/toi_bot_stt
)

### Generating Services

### Generating Module File
_generate_module_eus(toi_bot_stt
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/toi_bot_stt
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(toi_bot_stt_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(toi_bot_stt_generate_messages toi_bot_stt_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg" NAME_WE)
add_dependencies(toi_bot_stt_generate_messages_eus _toi_bot_stt_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(toi_bot_stt_geneus)
add_dependencies(toi_bot_stt_geneus toi_bot_stt_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS toi_bot_stt_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(toi_bot_stt
  "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/toi_bot_stt
)

### Generating Services

### Generating Module File
_generate_module_lisp(toi_bot_stt
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/toi_bot_stt
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(toi_bot_stt_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(toi_bot_stt_generate_messages toi_bot_stt_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg" NAME_WE)
add_dependencies(toi_bot_stt_generate_messages_lisp _toi_bot_stt_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(toi_bot_stt_genlisp)
add_dependencies(toi_bot_stt_genlisp toi_bot_stt_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS toi_bot_stt_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(toi_bot_stt
  "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/toi_bot_stt
)

### Generating Services

### Generating Module File
_generate_module_nodejs(toi_bot_stt
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/toi_bot_stt
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(toi_bot_stt_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(toi_bot_stt_generate_messages toi_bot_stt_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg" NAME_WE)
add_dependencies(toi_bot_stt_generate_messages_nodejs _toi_bot_stt_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(toi_bot_stt_gennodejs)
add_dependencies(toi_bot_stt_gennodejs toi_bot_stt_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS toi_bot_stt_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(toi_bot_stt
  "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/toi_bot_stt
)

### Generating Services

### Generating Module File
_generate_module_py(toi_bot_stt
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/toi_bot_stt
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(toi_bot_stt_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(toi_bot_stt_generate_messages toi_bot_stt_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_stt/msg/speechTT.msg" NAME_WE)
add_dependencies(toi_bot_stt_generate_messages_py _toi_bot_stt_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(toi_bot_stt_genpy)
add_dependencies(toi_bot_stt_genpy toi_bot_stt_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS toi_bot_stt_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/toi_bot_stt)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/toi_bot_stt
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(toi_bot_stt_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/toi_bot_stt)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/toi_bot_stt
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(toi_bot_stt_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/toi_bot_stt)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/toi_bot_stt
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(toi_bot_stt_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/toi_bot_stt)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/toi_bot_stt
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(toi_bot_stt_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/toi_bot_stt)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/toi_bot_stt\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/toi_bot_stt
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(toi_bot_stt_generate_messages_py std_msgs_generate_messages_py)
endif()
