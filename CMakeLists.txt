cmake_minimum_required(VERSION 3.6)
project(Sudoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp d_except.h d_matrix.h Board.cpp Board.h Cell.cpp Cell.h)
add_executable(Sudoku ${SOURCE_FILES})