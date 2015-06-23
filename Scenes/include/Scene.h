//
// Created by megaxela on 16.06.15.
//

#ifndef GRAPHICS_SYSTEM_SCENE_H
#define GRAPHICS_SYSTEM_SCENE_H

#include <SDL2/SDL.h>
#include "ResourceHolder.h"

// TODO: Изменить Scene api.
// TODO: Добавить класс мыши.
class Scene
{
public:
    Scene(SDL_Renderer *renderer=nullptr);
    virtual ~Scene();

    void loop();
    void stop();

    void setRenderer( SDL_Renderer *renderer);
    SDL_Renderer * renderer() const;

    void setResourceHolder( ResourceHolder *resourceHolder );
    ResourceHolder *resourceHolder() const;
protected:
    virtual void init();

    virtual void update();
    virtual void render();
    virtual void handleEvents();

    SDL_Renderer *_renderer;
    ResourceHolder *_resourceHolder;
    float _fps;

private:
    bool _loopDone;
};


#endif //GRAPHICS_SYSTEM_SCENE_H
