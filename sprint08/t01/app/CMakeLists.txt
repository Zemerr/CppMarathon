cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)

set(NAME classWithInitializerList)

project(${NAME})

set(SOURCE_EXE main.cpp)

add_subdirectory(src)

add_executable(${NAME} ${SOURCE_EXE})

target_link_libraries(${NAME} App)
