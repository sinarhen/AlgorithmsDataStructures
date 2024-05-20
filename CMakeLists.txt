cmake_minimum_required(VERSION 3.26)
project(Colorado C)

set(CMAKE_C_STANDARD 11)

include_directories(Course1/DataStructures)

add_executable(Colorado
        Course1/DataStructures/ll.c
        Course1/DataStructures/queue.c
        Course1/DataStructures/stack.c
        Course1/DataStructures/heap.c
        Course1/DataStructures/queue.h
        Course1/DataStructures/stack.h
        Course1/DataStructures/doubleqstack.c
        Course1/DataStructures/doubleqstack.h
        Course1/DataStructures/doublestackq.h
        Course1/DataStructures/binarytree.c)
add_executable(Bfc Course2/graph.c)
