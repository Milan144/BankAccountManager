cmake_minimum_required(VERSION 3.23)
project(files C)

set(CMAKE_C_STANDARD 99)

add_executable(files main.c files.h files.c)
