cmake_minimum_required(VERSION 2.8)
project(smartPointers)
include_directories(app)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE app/main.cpp)
add_executable(smartPointers ${SOURCE})
add_subdirectory(app)
target_link_libraries(smartPointers lib)

