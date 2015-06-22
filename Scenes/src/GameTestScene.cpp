//
// Created by megaxela on 21.06.15.
//

#include "GameTestScene.h"

GameTestScene::GameTestScene()
{

}

void GameTestScene::render()
{
    SDL_RenderClear( _renderer );

    map.renderLower( _renderer, 0, 0 );

    SDL_RenderPresent( _renderer );
}

void GameTestScene::update()
{
    Scene::update();
}

void GameTestScene::handleEvents()
{
    Scene::handleEvents();
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

void GameTestScene::init()
{
    map.setResourceHolder(_resourceHolder);
    map.loadMap("maps/test.tmx");
}
