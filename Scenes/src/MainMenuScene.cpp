//
// Created by megaxela on 17.06.15.
//

#include <GameTestScene.h>
#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() :
    Scene()
{
    _buttons.push_back(
            ScreenButton(nullptr, renderer(), 10, 10,
                         std::bind(&MainMenuScene::functionExit, this))
    );

    _buttons.push_back(
            ScreenButton(nullptr, renderer(), 10, 120,
                         std::bind(&MainMenuScene::functionLoadTestMap, this))
    );
}

void MainMenuScene::render()
{
    SDL_RenderClear(renderer());

    for (auto button : _buttons)
        button.render();

    SDL_RenderPresent(renderer());
}

void MainMenuScene::update()
{
    Scene::update();
}

void MainMenuScene::handleEvent( const SDL_Event &event )
{
    for (std::vector < ScreenButton >::iterator iterator = _buttons.begin();
         iterator != _buttons.end();
         iterator++)
        iterator->handleEvent(event);
}

void MainMenuScene::functionExit()
{
    stop();
}

void MainMenuScene::init()
{
    for (std::vector < ScreenButton >::iterator iterator = _buttons.begin();
         iterator != _buttons.end();
         iterator++)
        iterator->setRenderer(renderer());

    _buttons[0].setTexture( resourceHolder()->loadTexture("images/test_button.png"));
    _buttons[1].setTexture( resourceHolder()->loadTexture("images/test_button.png"));
}

void MainMenuScene::functionLoadTestMap()
{
    GameTestScene scene;

    scene.setResourceHolder(resourceHolder());
    scene.setRenderer(renderer());
    scene.setSettings( settings() );

    scene.loop();
}
