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
    void stop();

    void setRenderer( SDL_Renderer *renderer);
    SDL_Renderer * renderer() const;
protected:
    virtual void update();
    virtual void render();
    virtual void handleEvents();

    SDL_Renderer *_renderer;

private:
    bool _loopDone;
};


#endif //GRAPHICS_SYSTEM_SCENE_H