cmake_minimum_required(VERSION 3.17)
project(Assignment2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment2 main.c src/Fprocess.c Include/Fprocess.h src/CSV.c Include/CSV.h)