cmake_minimum_required(VERSION 2.8.9)
project (main)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# own lib used by the main executable
add_subdirectory(pi_duration_lib)

# main executable
add_executable(pi_main pi_main.cpp)
# link to own library and filesystem (starting with GCC 9, the C++17 std::filesystem components can be used without -lstdc++fs)
target_link_libraries(pi_main pi_duration -lstdc++fs)

# installation of the executable
install (TARGETS pi_main RUNTIME DESTINATION bin)