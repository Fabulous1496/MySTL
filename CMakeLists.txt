cmake_minimum_required(VERSION 3.27)
project(MySTL)

set(CMAKE_CXX_STANDARD 17)

add_executable(MySTL main.cpp
        List/List.h
        List/AList.h
        List/AList.cpp
        List/LList.h
        List/LList.cpp
)
