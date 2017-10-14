cmake_minimum_required(VERSION 3.5)
project(05_Word_Search)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(05_Word_Search ${SOURCE_FILES})