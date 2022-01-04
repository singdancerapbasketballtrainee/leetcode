cmake_minimum_required(VERSION 3.21)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp
        main.cpp
        solution.cpp
        solution.h)
