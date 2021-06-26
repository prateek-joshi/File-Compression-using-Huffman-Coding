cmake_minimum_required(VERSION 3.0)

# set the project name
project(Huffman-Coding VERSION 1.0)

# flags

# files

# include
include_directories( ./include ./src)

# add the executable
add_executable(binary ./src/main.cpp)