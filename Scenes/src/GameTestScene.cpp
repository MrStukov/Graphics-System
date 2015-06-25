//
// Created by megaxela on 21.06.15.
//

#include "GameTestScene.h"

GameTestScene::GameTestScene()
{
    _camera.setTargetPosition(Vector2(20, 20));
    _camera.setMovingType(Camera::CameraMovingType_Curve);
}

void GameTestScene::render()
{
    SDL_RenderClear( renderer() );

    _map.renderLower( renderer(), -_camera.x(), -_camera.y() );

    SDL_RenderPresent( renderer() );
}

void GameTestScene::update()
{
    Scene::update();
    _camera.update();
}

void GameTestScene::handleEvent( const SDL_Event &event )
{

}

void GameTestScene::init()
{
    _map.setResourceHolder( resourceHolder() );
    _map.loadMap("maps/test.tmx");
}
