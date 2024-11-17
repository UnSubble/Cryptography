cmake_minimum_required(VERSION 3.28)
project(hashing C)

set(CMAKE_C_STANDARD 17)

add_executable(main.c
        hash.h
        hash.c
        main.c
)
