//
// Created by megaxela on 17.06.15.
//

#include "ScreenButton.h"

ScreenButton::ScreenButton() :
    ScreenItem( nullptr )
{
    _callbackFunction = nullptr;
    _state = ButtonState_Released;
    _texture = nullptr;

    _textureHeight = 0;
    _textureWidth = 0;
    _dstRect.x = 0;
    _dstRect.y = 0;
    _dstRect.w = 0;
    _dstRect.h = 0;
}

ScreenButton::ScreenButton(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, void (*callback)()) :
    ScreenItem( renderer )
{
    _state = ButtonState_Released;

    setTexture(texture);

    _dstRect.x = x;
    _dstRect.y = y;
    _dstRect.w = _textureWidth;
    _dstRect.h = _textureHeight;
}

ScreenButton::~ScreenButton()
{

}

void ScreenButton::render()
{
    // TODO: Исправить printf на logger
    if (!_renderer) //TODO: #1
        printf("[ScreenButton::render] Error: Renderer was not set.\n");

    if (!_texture) // TODO: #2
        printf("[ScreenButton::render] Error: Texture was not set.\n");

    if (!_renderer || !_texture)
        return;

    int partSize = _textureHeight / 3;
    SDL_Rect sourceRect;

    switch (_state)
    {
        case ButtonState_Released:
            sourceRect = {0, 0, _textureWidth, partSize};

            if (SDL_RenderCopy(_renderer, _texture, &sourceRect, &_dstRect) != 0) // TODO: #3
                printf("[ScreenButton::render] Error: Can't copy texture to renderer. Error: %s\n",
                       SDL_GetError());
            break;
        case ButtonState_Hover:
            sourceRect = {0, partSize, _textureWidth, partSize};

            if (SDL_RenderCopy(_renderer, _texture, &sourceRect, &_dstRect) != 0) // TODO: #4
                printf("[ScreenButton::render] Error: Can't copy texture to renderer. Error: %s\n",
                       SDL_GetError());
            break;
        case ButtonState_Pressed:
            sourceRect = {0, partSize * 2, _textureWidth, partSize};

            if (SDL_RenderCopy(_renderer, _texture, &sourceRect, &_dstRect) != 0) // TODO: #5
                printf("[ScreenButton::render] Error: Can't copy texture to renderer. Error: %s\n",
                       SDL_GetError());
            break;
        default:
            // TODO: #5
            printf("[ScreenButton::render] Error: Unexpected behaviour. Can't identificate button state.\n");
            break;
    }
}

void ScreenButton::setTexture(SDL_Texture *texture)
{
    _texture = texture;
    // TODO: Исправить printf на logger
    if (texture)
    {
        if (SDL_QueryTexture(_texture, NULL, NULL, &_textureWidth, &_textureHeight) != 0)
        {
            // TODO: #1
            printf("[ScreenButton::setTexture] Can't get texture size. Error: %s\n", SDL_GetError());
            _textureHeight = 0;
            _textureWidth = 0;
        }
    }
    else
    {
        _textureHeight = 0;
        _textureWidth = 0;
    }

    _dstRect.w = _textureWidth;
    _dstRect.h = _textureHeight;
}

SDL_Texture *ScreenButton::texture() const
{
    return _texture;
}

void ScreenButton::handleEvent(SDL_Event *event)
{
    switch (event->type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if (_state == ButtonState_Hover)
            {
                _state = ButtonState_Pressed;

                if (_callbackFunction)
                    _callbackFunction();
            }
            break;

        case SDL_MOUSEMOTION:
            if (event->motion.x > _dstRect.x &&
                event->motion.x < (_dstRect.x + _dstRect.w) &&
                event->motion.y > _dstRect.y &&
                event->motion.y < (_dstRect.y + _dstRect.h))
                _state = ButtonState_Hover;
            else if (_state == ButtonState_Hover)
                _state = ButtonState_Released;
            break;
        default:
            break;
    }
}

void ScreenButton::setPosition(int x, int y)
{
    _dstRect.x = x;
    _dstRect.y = y;
}

int ScreenButton::x() const
{
    return _dstRect.x;
}

int ScreenButton::y() const
{
    return _dstRect.y;
}

void ScreenButton::setCallback(void (*callBack)())
{
    _callbackFunction = callBack;
}
