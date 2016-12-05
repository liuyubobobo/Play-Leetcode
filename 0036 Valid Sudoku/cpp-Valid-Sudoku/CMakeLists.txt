cmake_minimum_required(VERSION 3.5)
project(cpp_Valid_Sudoku)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(cpp_Valid_Sudoku ${SOURCE_FILES})