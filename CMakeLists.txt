cmake_minimum_required(VERSION 3.21)
project(data_struct C)

set(CMAKE_C_STANDARD 11)

add_executable(data_struct
        Linked-list/index.c sequence-list/index.c)

add_executable(Linked-list Linked-list/index.c)

add_executable(index sequence-list/index.c)
