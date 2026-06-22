cmake_minimum_required(VERSION 4.2)
project(cTimedTyperV1 C)

set(CMAKE_C_STANDARD 23)

add_executable(cTimedTyperV1 main.c
        game.c
        game.h
        words.c
        words.h
        ldistance.c
        ldistance.h)
