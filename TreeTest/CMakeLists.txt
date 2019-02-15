cmake_minimum_required(VERSION 3.12)
project(TreeTest C)

set(CMAKE_C_STANDARD 99)

add_executable(TreeTest main.c TreeTest.h TreeTest.c Queue.c Queue.h)