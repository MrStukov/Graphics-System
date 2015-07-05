//
// Created by megaxela on 21.06.15.
//

#include "GameTestScene.h"

GameTestScene::GameTestScene()
{
    _camera.setMovingType(Camera::CameraMovingType_Curve);
}

void GameTestScene::render()
{
    SDL_RenderClear( renderer() );

    _map.renderLower( renderer(), -_camera.x(), -_camera.y() );

    _mainPlayer.render();

    _map.renderUpper( renderer(), -_camera.x(), -_camera.y() );
    _map.renderColliders(renderer(), -_camera.x(), -_camera.y());

    SDL_RenderPresent( renderer() );
}

void GameTestScene::update()
{
    Scene::update();
    _camera.update();
    _cameraFollowController.update();

    // TODO: Добавить settings с настройками клавиш. Переделать саму систему.

    Colliders::Rectangle playerCollider = _mainPlayer.getCollider();
    if (keyboardHolder().isKeyPressed(SDLK_w) &&
            !_map.collidersHolder().isColliding(playerCollider.margin(
                    (int) _mainPlayer.speed(), Colliders::Direction_Top)))
        _mainPlayer.move( Player::Direction_Top );

    if (keyboardHolder().isKeyPressed(SDLK_a) &&
            !_map.collidersHolder().isColliding(playerCollider.margin(
                    (int) _mainPlayer.speed(), Colliders::Direction_Left)))
        _mainPlayer.move( Player::Direction_Left );

    if (keyboardHolder().isKeyPressed(SDLK_s) &&
            !_map.collidersHolder().isColliding(playerCollider.margin(
                    (int) _mainPlayer.speed(), Colliders::Direction_Bottom)))
        _mainPlayer.move( Player::Direction_Bottom );

    if (keyboardHolder().isKeyPressed(SDLK_d) &&
            !_map.collidersHolder().isColliding(playerCollider.margin(
                    (int) _mainPlayer.speed(), Colliders::Direction_Right)))
        _mainPlayer.move( Player::Direction_Right );

}

void GameTestScene::handleEvent( const SDL_Event &event )
{

}

void GameTestScene::init()
{
    _map.setResourceHolder( resourceHolder() );
    _map.loadMap("maps/test.tmx");

    _mainPlayer.setRenderer( renderer() );
    _mainPlayer.setTexture( resourceHolder()->loadTexture("images/player_replace.png"));
    _mainPlayer.setCamera( &_camera );
    _mainPlayer.setPosition( {0, 0} );

    _cameraFollowController.setCamera( &_camera );
    _cameraFollowController.setFollowTarget( &_mainPlayer );
    _cameraFollowController.setSettings( settings() );
}
