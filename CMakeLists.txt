cmake_minimum_required(VERSION 3.24)
project(Project3_Transparent_Urban_Living)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/main)

add_executable(Project3_Transparent_Urban_Living
        src/main/graph_implementation.cpp
        src/main/graph_implementation.h
        src/main/main.cpp src/main/city.cpp src/main/city.h)
