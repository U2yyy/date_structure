cmake_minimum_required(VERSION 3.22)
project(sort C)

set(CMAKE_C_STANDARD 99)



add_executable(Bubble_sort Bubble_sort.c)
add_executable(selection_sort selection_sort.c)
add_executable(insert_sort insert_sort.c)