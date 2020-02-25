# example of creation of own library
cmake_minimum_required(VERSION 2.8.9)
project (awesome_lib)

# create library
add_library(awesome STATIC src/awesome_class.cpp)
target_include_directories(awesome PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# install library and its headers
install(TARGETS awesome DESTINATION lib)
install(FILES include/awesome_lib/awesome_class.h DESTINATION include/awesome_lib)