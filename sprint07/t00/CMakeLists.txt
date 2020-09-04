cmake_minimum_required(VERSION 2.8)
project(vector)
include_directories(app)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE app/main.cpp)
add_executable(vector ${SOURCE})
add_subdirectory(app)

