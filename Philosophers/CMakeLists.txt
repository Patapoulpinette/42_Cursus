cmake_minimum_required(VERSION 3.22)
project(dbouron C)

set(CMAKE_C_STANDARD 11)

add_executable(dbouron
        main.c philo.h parsing.c utils.c error_msg.c parsing2.c)
