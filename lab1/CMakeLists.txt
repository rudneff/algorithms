cmake_minimum_required(VERSION 3.1)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(lab1 ${SOURCE_FILES} all_multipliers.h all_multipliers.cpp)