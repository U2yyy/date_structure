cmake_minimum_required(VERSION 3.22)
project(dynamicArray C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic")
set(CMAKE_C_STANDARD 99)

add_executable(dynamicArray main.c)
add_executable(copyone copyone.c)