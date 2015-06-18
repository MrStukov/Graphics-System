//
// Created by megaxela on 17.06.15.
//

#include "MainMenuScene.h"

MainMenuScene::MainMenuScene( SDL_Renderer *renderer) :
    Scene(renderer)
{
    _buttons.push_back(
            ScreenButton(nullptr, _renderer, 10, 10, nullptr)
    );
}

void MainMenuScene::render()
{
    SDL_RenderClear(_renderer);



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
