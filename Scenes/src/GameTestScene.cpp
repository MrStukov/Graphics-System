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

void GameTestScene::handleEvent( const SDL_Event &event )
{

}

void GameTestScene::init()
{
    map.setResourceHolder(_resourceHolder);
    map.loadMap("maps/test.tmx");
}
