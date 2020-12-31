cmake_minimum_required(VERSION 3.5)
project(01_Design_HashSet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(01_Design_HashSet ${SOURCE_FILES})