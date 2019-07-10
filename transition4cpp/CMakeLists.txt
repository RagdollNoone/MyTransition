cmake_minimum_required(VERSION 3.13)
project(transition4cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(transition4cpp src/Machine.cpp
        src/EventData.cpp
        src/Event.cpp
        src/Model.cpp
        src/Transition.cpp
        src/State.cpp
        src/Condition.cpp
        src/Matter.cpp
        src/main.cpp)