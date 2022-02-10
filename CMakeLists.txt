cmake_minimum_required(VERSION 3.21)
project(linkedlist C)

set(CMAKE_C_STANDARD 99)

add_library(linkedlist src/linked_list.c)

add_executable(example example.c)
target_link_libraries(example linkedlist)