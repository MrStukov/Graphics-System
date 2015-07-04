//
// Created by megaxela on 04.07.15.
//

#include "Entity.h"

Entity::Entity(SDL_Renderer *renderer)
{
    _renderer = renderer;
    _position = {0, 0};
    _height = 0;
    _width = 0;
    _texture = nullptr;
    _camera = nullptr;
}

Entity::~Entity()
{

}

void Entity::render()
{

}

void Entity::setPosition(const Vector2 &position)
{
    _position = position;
}

Vector2 Entity::position() const
{
    return _position;
}

void Entity::setTexture(SDL_Texture *texture)
{
    if (!texture)
        return;

    _texture = texture;
    if (SDL_QueryTexture(_texture, NULL, NULL, (int *) &_width, (int *) &_height))
        printf("[Entity::setTexture] Error: Can't get texture size. Error: %s\n", SDL_GetError());
}

SDL_Texture *Entity::texture() const
{
    return _texture;
}

unsigned int Entity::width() const
{
    return _width;
}

unsigned int Entity::height() const
{
    return _height;
}

void Entity::setRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

SDL_Renderer *Entity::renderer() const
{
    return _renderer;
}

void Entity::setCamera(Camera *camera)
{
    _camera = camera;
}

Camera *Entity::camera() const
{
    return _camera;
}

void Entity::update(float deltaTime)
{

}

void Entity::handleEvent(SDL_Event *event)
{

}
