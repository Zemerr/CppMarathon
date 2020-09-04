cmake_minimum_required(VERSION 2.8)
project(simpleWorkerV2)
include_directories(app)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE app/main.cpp)
add_executable(simpleWorkerV2 ${SOURCE})
add_subdirectory(app)


