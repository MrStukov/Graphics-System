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
    _mainPlayer.renderCollider( -_camera.x(), -_camera.y());

    SDL_RenderPresent( renderer() );
}

void GameTestScene::update()
{
    Scene::update();
    _camera.update();
    _cameraFollowController.update();

    // TODO: Добавить settings с настройками клавиш. Переделать саму систему.

    if (keyboardHolder().isKeyPressed(SDLK_w))
        _mainPlayer.move( Player::Direction_Top );

    if (keyboardHolder().isKeyPressed(SDLK_a))
        _mainPlayer.move( Player::Direction_Left );

    if (keyboardHolder().isKeyPressed(SDLK_s))
        _mainPlayer.move( Player::Direction_Bottom );

    if (keyboardHolder().isKeyPressed(SDLK_d))
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
    _mainPlayer.setPosition( {512, 512} );
    _mainPlayer.setCollisionSubscriber( &_collisionControllerSubscriber );

    _cameraFollowController.setCamera( &_camera );
    _cameraFollowController.setFollowTarget( &_mainPlayer );
    _cameraFollowController.setSettings( settings() );

    _collisionControllerSubscriber.update( _map.collisionController() );
}
