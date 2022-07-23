cmake_minimum_required(VERSION 3.22)
project(dbouron C)

set(CMAKE_C_STANDARD 11)

add_executable(dbouron
        main.c philo.h utils.c messages.c parsing.c thread_man_exemple.c execution.c actions.c time.c)
