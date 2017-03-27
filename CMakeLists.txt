cmake_minimum_required(VERSION 3.6)
project(Sodoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp d_except.h d_matrix.h Board.cpp Board.h)
add_executable(Sodoku ${SOURCE_FILES})