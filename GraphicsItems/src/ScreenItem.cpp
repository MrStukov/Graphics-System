//
// Created by megaxela on 18.06.15.
//

#include "ScreenItem.h"

ScreenItem::ScreenItem(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

ScreenItem::~ScreenItem()
{

}

void ScreenItem::update(float deltaTime)
{

}

void ScreenItem::render()
{

}

void ScreenItem::setRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

SDL_Renderer *ScreenItem::renderer() const
{
    return _renderer;
}

void ScreenItem::handleEvent(SDL_Event *event)
{

}
