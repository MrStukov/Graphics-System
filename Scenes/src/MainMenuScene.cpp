//
// Created by megaxela on 17.06.15.
//

#include <GameTestScene.h>
#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() :
    Scene()
{
    _buttons.push_back(
            ScreenButton(nullptr, _renderer, 10, 10,
                         std::bind(&MainMenuScene::functionExit, this))
    );

    _buttons.push_back(
            ScreenButton(nullptr, _renderer, 10, 120,
                         std::bind(&MainMenuScene::functionLoadTestMap, this))
    );
}

void MainMenuScene::render()
{
    SDL_RenderClear(_renderer);

//    std::for_each( _buttons.begin(), _buttons.end(), std::mem_fun_ref(&ScreenButton::render));

    for (auto button : _buttons)
    {
        button.render();
    }

    SDL_RenderPresent(_renderer);
}

void MainMenuScene::update()
{
    Scene::update();
}

void MainMenuScene::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        for (std::vector < ScreenButton >::iterator iterator = _buttons.begin();
             iterator != _buttons.end();
             iterator++)
            iterator->handleEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                stop();
                break;
            default:
                break;
        }
    }
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
        iterator->setRenderer(_renderer);

    _buttons[0].setTexture( _resourceHolder->loadTexture("images/test_button.png"));
    _buttons[1].setTexture( _resourceHolder->loadTexture("images/test_button.png"));
}

void MainMenuScene::functionLoadTestMap()
{
    GameTestScene scene;

    scene.setResourceHolder(_resourceHolder);
    scene.setRenderer(_renderer);

    scene.loop();
}
