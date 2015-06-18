cmake_minimum_required(VERSION 3.1)
project(Graphics_System)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp)

include_directories(
    Scenes/include
    GraphicsItems/include
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../Graphics-System_executable/)
add_executable(Graphics_System ${SOURCE_FILES}
    Application.cpp
    Application.h
    Scenes/src/Scene.cpp
    Scenes/include/Scene.h
    Scenes/src/MainMenuScene.cpp
    Scenes/include/MainMenuScene.h
    GraphicsItems/src/ScreenButton.cpp
    GraphicsItems/include/ScreenButton.h
    GraphicsItems/src/ScreenItem.cpp
    GraphicsItems/include/ScreenItem.h
)

target_link_libraries(Graphics_System -lSDL2)
