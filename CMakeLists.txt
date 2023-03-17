cmake_minimum_required(VERSION 3.24)
project(CppProjects)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CppProjects
        basics.cpp
        basics.h ../Intervals/intervalsOperations.cpp)
