cmake_minimum_required(VERSION 3.26)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 17)

add_executable(advent_of_code
        main.cpp
        2023/day_01/trebuchet.h
        2023/day_01/second_part.cpp
        2023/day_01/first_part.cpp
)