cmake_minimum_required(VERSION 3.0)

file(GLOB SOURCE *.cpp)

add_library(App STATIC ${SOURCE})


