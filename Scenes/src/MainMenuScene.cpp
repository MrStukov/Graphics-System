//
// Created by megaxela on 17.06.15.
//

#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() :
    Scene()
{

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