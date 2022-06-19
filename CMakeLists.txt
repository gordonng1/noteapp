cmake_minimum_required(VERSION 3.22)
project(noteapp)

set(CMAKE_CXX_STANDARD 14)

add_executable(noteapp main.cpp Note.cpp Note.h)
