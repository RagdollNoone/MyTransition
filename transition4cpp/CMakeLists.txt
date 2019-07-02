cmake_minimum_required(VERSION 3.13)
project(transition4cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(transition4cpp src/main.cpp
        src/State.cpp
        src/State.h
        src/Object.h
        src/Machine.cpp
        src/Machine.h)