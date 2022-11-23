cmake_minimum_required(VERSION 3.23)
project(coursC C)

set(CMAKE_C_STANDARD 99)

add_executable(coursC main.c controller.h controller.c view.c view.h)
