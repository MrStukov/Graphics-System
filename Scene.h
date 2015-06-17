//
// Created by megaxela on 16.06.15.
//

#ifndef GRAPHICS_SYSTEM_SCENE_H
#define GRAPHICS_SYSTEM_SCENE_H

#include <SDL2/SDL.h>

class Scene
{
public:
    Scene(SDL_Renderer *renderer=nullptr);
    virtual ~Scene();

    void loop();

protected:
    virtual void update();
    virtual void render();
    virtual void handleEvents();

    SDL_Renderer *_renderer;
};


#endif //GRAPHICS_SYSTEM_SCENE_H
