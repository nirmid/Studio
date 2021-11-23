cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(untitled
        include/Action.h
        include/Customer.h
        include/Studio.h
        include/Trainer.h
        include/Workout.h
        src/main.cpp
        src/Workout.cpp src/Studio.cpp src/Customer.cpp src/Trainer.cpp src/Action.cpp)
