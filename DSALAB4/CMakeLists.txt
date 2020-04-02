cmake_minimum_required(VERSION 3.13)
project(DSALAB4)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSALAB4 main.cpp SMMIterator.cpp SMMIterator.h SortedMultiMap.cpp SortedMultiMap.h DynamicVector.h Node.cpp Node.h)