//
// Created by megaxela on 21.06.15.
//

#ifndef GRAPHICS_SYSTEM_GAMETESTSCENE_H
#define GRAPHICS_SYSTEM_GAMETESTSCENE_H


#include <TiledMap.h>
#include <Camera.h>
#include <Player.h>
#include <CameraFollowController.h>
#include "Scene.h"

class GameTestScene : public Scene
{
public:
    GameTestScene();

protected:
    void render() override;
    void update() override;
    void handleEvent( const SDL_Event &event) override;

    virtual void init() override;

private:
    Player _mainPlayer;
    TiledMap _map;
    Camera _camera;
    CameraFollowController _cameraFollowController;
};


#endif //GRAPHICS_SYSTEM_GAMETESTSCENE_H
