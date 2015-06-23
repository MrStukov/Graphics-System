//
// Created by megaxela on 21.06.15.
//

#ifndef GRAPHICS_SYSTEM_GAMETESTSCENE_H
#define GRAPHICS_SYSTEM_GAMETESTSCENE_H


#include <TiledMap.h>
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
    TiledMap map;
};


#endif //GRAPHICS_SYSTEM_GAMETESTSCENE_H
