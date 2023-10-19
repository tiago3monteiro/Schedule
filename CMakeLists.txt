cmake_minimum_required(VERSION 3.26)
project(Schedule_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Schedule_Project main.cpp
        Student.cpp
        Student.h
        Block.cpp
        Block.h
        ClassForUc.cpp
        ClassForUc.h
        ScheduleUC.cpp
        ScheduleUC.h
        Application.cpp
        Application.h
)
