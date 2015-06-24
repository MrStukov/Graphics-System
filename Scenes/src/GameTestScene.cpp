//
// Created by megaxela on 21.06.15.
//

#include "GameTestScene.h"

GameTestScene::GameTestScene()
{

}

void GameTestScene::render()
{
    SDL_RenderClear( renderer() );

    map.renderLower( renderer(), 0, 0 );

    SDL_RenderPresent( renderer() );
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
    map.setResourceHolder( resourceHolder() );
    map.loadMap("maps/test.tmx");
}
