//
// Created by megaxela on 16.06.15.
//

#include "Scene.h"

Scene::Scene(SDL_Renderer *renderer)
{
    _renderer = renderer;
    _loopDone = false;
}

Scene::~Scene()
{

}

void Scene::loop()
{
    init();
    _loopDone = false;
    unsigned int ticks = 0;
    unsigned int resultTicks = SDL_GetTicks();
    unsigned int difference = 0;
    _fps = 60;
    unsigned int expectedTicks = 1000 / 60;
    while (!_loopDone)
    {
        handleEvents();
        update();
        render();

        // Ожидание разницы в кадрах
        ticks = resultTicks;
        resultTicks = SDL_GetTicks();
        difference = resultTicks - ticks;

        _fps = (_fps + 1000.0f / difference) / 2;
        printf("FPS: %f\n", _fps);
        if (expectedTicks > resultTicks)
            SDL_Delay( expectedTicks - difference );
    }
}

void Scene::update()
{

}

void Scene::render()
{

}

void Scene::handleEvents()
{

}

void Scene::setRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

SDL_Renderer * Scene::renderer() const
{
    return _renderer;
}

void Scene::stop()
{
    _loopDone = true;
}

void Scene::setResourceHolder(ResourceHolder *resourceHolder)
{
    _resourceHolder = resourceHolder;
}

ResourceHolder *Scene::resourceHolder() const
{
    return _resourceHolder;
}

void Scene::init()
{

}
