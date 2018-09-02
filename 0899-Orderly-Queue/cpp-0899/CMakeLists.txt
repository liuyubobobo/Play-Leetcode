cmake_minimum_required(VERSION 3.5)
project(cpp_0899)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(cpp_0899 ${SOURCE_FILES})