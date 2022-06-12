cmake_minimum_required(VERSION 3.22)
project(Graph C)

set(CMAKE_C_STANDARD 99)

add_executable(directed_graph undirected_graph_Matrix.c)
add_executable(undirected_graph_Form undirected_graph_Form.c)