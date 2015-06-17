//
// Created by megaxela on 17.06.15.
//

#include "ScreenButton.h"

ScreenButton::ScreenButton()
{
    _renderer = nullptr;
    _texture = nullptr;

    _dstRect.x = 0;
    _dstRect.y = 0;
    _dstRect.w = 0;
    _dstRect.h = 0;
}

ScreenButton::ScreenButton(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, unsigned int w, unsigned int h)
{
    _renderer = renderer;
    _texture = texture;

    _dstRect.x = x;
    _dstRect.y = y;
    _dstRect.w = w;
    _dstRect.h = h;
}

ScreenButton::~ScreenButton()
{

}


void ScreenButton::setRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

SDL_Renderer *ScreenButton::renderer() const
{
    return _renderer;
}

void ScreenButton::render()
{
    if (!_renderer)
        printf("[ScreenButton::render] Error: Renderer was not set.\n");

    if (!_texture)
        printf("[ScreenButton::render] Error: Texture was not set.\n");

    if (!_renderer || !_texture)
        return;

    SDL_RenderCopy(_renderer, _texture,)
}

void ScreenButton::setTexture(SDL_Texture *texture)
{
    _texture = texture;
}

SDL_Texture *ScreenButton::texture() const
{
    return _texture;
}

void ScreenButton::update(float deltaTime)
{

}

void ScreenButton::handleEvent(SDL_Event *event)
{
    switch (event->type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if (//TODO: Last finish
                event->motion.x > _dstRect.x &&
                event->motion.x < (_dstRect.x + _dstRect.w) &&
                event->motion.y > _dstRect.y &&
                event->motion.y < (_dstRect.y + _dstRect.h))

            break;

        default:
            break;
    }
}
