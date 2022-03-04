cmake_minimum_required(VERSION 3.17)
project(CG_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/headers)

add_executable(CG_Project
        src/headers/point.hpp
        src/box.cpp
        src/cone.cpp
        src/plane.cpp
        src/point.cpp
        src/sphere.cpp)
