cmake_minimum_required(VERSION 3.12)
project(AdjacencyTest C)

set(CMAKE_C_STANDARD 99)

add_executable(AdjacencyTest main.c Adjacency.h Adjacency.c Queue.c Queue.h)