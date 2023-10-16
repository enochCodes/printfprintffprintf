cmake_minimum_required(VERSION 3.26)
project(printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(printf
        tests/main.c
        _printf.c
        main.h)
