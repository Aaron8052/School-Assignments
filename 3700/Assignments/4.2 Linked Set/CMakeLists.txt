cmake_minimum_required(VERSION 3.30)
project(4_2_Linked_Set)

set(CMAKE_CXX_STANDARD 20)

add_executable(4_2_Linked_Set LinkedSetDriver.cpp
        LinkedSet.h
        LinkedSet.hpp
        Node.h
        Node.cpp)
