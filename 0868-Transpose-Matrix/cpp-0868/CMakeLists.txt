cmake_minimum_required(VERSION 3.5)
project(A)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(A ${SOURCE_FILES})