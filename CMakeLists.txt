cmake_minimum_required(VERSION 3.1)
project(Graphics_System)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp)

add_executable(Graphics_System ${SOURCE_FILES} Application.cpp Application.h Scene.cpp Scene.h)
target_link_libraries(Graphics_System -lSDL2)