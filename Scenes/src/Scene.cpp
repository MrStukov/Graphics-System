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
    while (!_loopDone)
    {
        handleEvents();
        update();
        render();
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
