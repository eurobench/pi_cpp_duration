cmake_minimum_required(VERSION 2.8.9)
project (hello)

# own lib used by the main executable
add_subdirectory(awesome_lib)

# main executable
add_executable(hello_world hello_world.cpp)
# link to own library
target_link_libraries(hello_world awesome)

# installation of the executable
install (TARGETS hello_world RUNTIME DESTINATION bin)