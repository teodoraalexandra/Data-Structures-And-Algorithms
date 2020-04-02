cmake_minimum_required(VERSION 3.13)
project(SDA_lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDA_lab1 main.cpp Bag.cpp Bag.h BagIterator.cpp BagIterator.h DynamicArray.cpp DynamicArray.h)