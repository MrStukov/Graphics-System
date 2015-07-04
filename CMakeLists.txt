cmake_minimum_required(VERSION 3.1)
project(Graphics_System)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp)

include_directories(
    Libraries/Tinyxml2
    Scenes/include
    GraphicsItems/include
    Tools/include
    LogicItems/include
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../Graphics-System_executable/)
add_executable(Graphics_System ${SOURCE_FILES}
    Libraries/Tinyxml2/tinyxml2.cpp
    Libraries/Tinyxml2/tinyxml2.h
    Scenes/src/Scene.cpp
    Scenes/include/Scene.h
    Scenes/src/MainMenuScene.cpp
    Scenes/include/MainMenuScene.h
    Scenes/src/GameTestScene.cpp
    Scenes/include/GameTestScene.h
    GraphicsItems/src/ScreenButton.cpp
    GraphicsItems/include/ScreenButton.h
    Tools/src/ResourceHolder.cpp
    Tools/include/ResourceHolder.h
    Tools/src/TiledMap.cpp
    Tools/include/TiledMap.h
    Tools/src/Compression.cpp
    Tools/include/Compression.h
    Tools/src/Colliders.cpp
    Tools/include/Colliders.h
    Tools/src/Camera.cpp
    Tools/include/Camera.h
    Tools/src/Vector2.cpp
    Tools/include/Vector2.h
    Tools/src/Application.cpp
    Tools/include/Application.h
    LogicItems/src/Player.cpp
    LogicItems/include/Player.h
    Tools/src/CameraFollowController.cpp
    Tools/include/CameraFollowController.h
    GraphicsItems/src/Entity.cpp
    GraphicsItems/include/Entity.h
    Tools/src/SettingsHolder.cpp
    Tools/include/SettingsHolder.h
)

target_link_libraries(Graphics_System -lSDL2 -lSDL2_image -lz)
