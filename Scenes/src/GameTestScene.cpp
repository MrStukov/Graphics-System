//
// Created by megaxela on 21.06.15.
//

#include "GameTestScene.h"

GameTestScene::GameTestScene()
{

}

void GameTestScene::render()
{
    Scene::render();
}

void GameTestScene::update()
{
    Scene::update();
}

void GameTestScene::handleEvents()
{
    Scene::handleEvents();
}

void GameTestScene::init()
{
    map.setResourceHolder(_resourceHolder);
    map.loadMap("maps/test.tmx");
}
