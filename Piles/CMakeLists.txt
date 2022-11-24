cmake_minimum_required(VERSION 3.23)
project(piles C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(piles
        main.c
        pile.c
        pile.h)
