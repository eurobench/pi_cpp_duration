# example of creation of own library
cmake_minimum_required(VERSION 2.8.9)
project (pi_duration_lib)

# create library
add_library(pi_duration STATIC src/pi_duration.cpp)
target_include_directories(pi_duration PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# install library and its headers
install(TARGETS pi_duration DESTINATION lib)
install(FILES include/pi_duration_lib/pi_duration.h DESTINATION include/pi_duration_lib)