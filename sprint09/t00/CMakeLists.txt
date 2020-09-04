cmake_minimum_required(VERSION 2.8)
project(simpleWorkerV1)
include_directories(app)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE app/main.cpp)
add_executable(simpleWorkerV1 ${SOURCE})
add_subdirectory(app)


