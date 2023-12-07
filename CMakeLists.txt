cmake_minimum_required(VERSION 3.26)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(2023)
add_subdirectory(utils)

add_executable(advent_of_code main.cpp)

target_link_libraries(advent_of_code 2023)
target_link_libraries(advent_of_code utils)
