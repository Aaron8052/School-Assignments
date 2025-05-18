cmake_minimum_required(VERSION 3.31)
project(14_1_Circular_Linked_Queue)

set(CMAKE_CXX_STANDARD 11)

add_executable(14_1_Circular_Linked_Queue
        CircularLinkedQueueDriver.cpp
        PrecondViolationException.cpp)
