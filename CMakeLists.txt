cmake_minimum_required(VERSION 3.1)
project(Graphics_System)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp)

include_directories(
    Scenes/include
    GraphicsItems/include
    Tools/include
    Libraries/Tinyxml2
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../Graphics-System_executable/)
add_executable(Graphics_System ${SOURCE_FILES}
    Libraries/Tinyxml2/tinyxml2.cpp
    Libraries/Tinyxml2/tinyxml2.h
    Tools/src/Application.cpp
    Tools/include/Application.h
    Scenes/src/Scene.cpp
    Scenes/include/Scene.h
    Scenes/src/MainMenuScene.cpp
    Scenes/include/MainMenuScene.h
    GraphicsItems/src/ScreenButton.cpp
    GraphicsItems/include/ScreenButton.h
    GraphicsItems/src/ScreenItem.cpp
    GraphicsItems/include/ScreenItem.h
    Tools/src/ResourceHolder.cpp
    Tools/include/ResourceHolder.h
    Tools/src/TiledMap.cpp
    Tools/include/TiledMap.h
    Tools/src/Compression.cpp
    Tools/include/Compression.h
    Scenes/src/GameTestScene.cpp
    Scenes/include/GameTestScene.h
Tools/src/Colliders.cpp Tools/include/Colliders.h)

target_link_libraries(Graphics_System -lSDL2 -lSDL2_image -lz)
