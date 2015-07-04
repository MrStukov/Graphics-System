//
// Created by megaxela on 17.06.15.
//

#include "ScreenButton.h"

ScreenButton::ScreenButton() :
        Entity( nullptr )
{
    _callbackFunction = nullptr;
    _state = ButtonState_Released;

    _dstRect.x = 0;
    _dstRect.y = 0;
    _dstRect.w = 0;
    _dstRect.h = 0;
}

ScreenButton::ScreenButton(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, std::function<void()> callback) :
        Entity( renderer )
{
    _state = ButtonState_Released;

    setTexture(texture);

    _dstRect.x = x;
    _dstRect.y = y;
    _dstRect.w = width();
    _dstRect.h = height() / 3;
    _callbackFunction = callback;
}

ScreenButton::~ScreenButton()
{

}

void ScreenButton::render()
{
    // TODO: Исправить printf на logger
    if (!renderer())
        printf("[ScreenButton::render] Error: Renderer was not set.\n");

    if (!texture())
        printf("[ScreenButton::render] Error: Texture was not set.\n");

    if (!renderer() || !texture())
        return;

    int partSize = height() / 3;
    SDL_Rect sourceRect;

    switch (_state)
    {
        case ButtonState_Released:
            sourceRect = {0, 0, (int) width(), partSize};
            if (SDL_RenderCopy(renderer(), texture(), &sourceRect, &_dstRect) != 0)
                printf("[ScreenButton::render] Error: Can't copy texture to renderer. Error: %s\n",
                       SDL_GetError());
            break;
        case ButtonState_Hover:
            sourceRect = {0, partSize, (int) width(), partSize};

            if (SDL_RenderCopy(renderer(), texture(), &sourceRect, &_dstRect) != 0)
                printf("[ScreenButton::render] Error: Can't copy texture to renderer. Error: %s\n",
                       SDL_GetError());
            break;
        case ButtonState_Pressed:
            sourceRect = {0, partSize * 2, (int) width(), partSize};

            if (SDL_RenderCopy(renderer(), texture(), &sourceRect, &_dstRect) != 0)
                printf("[ScreenButton::render] Error: Can't copy texture to renderer. Error: %s\n",
                       SDL_GetError());
            break;
        default:
            printf("[ScreenButton::render] Error: Unexpected behaviour. Can't identificate button state.\n");
            break;
    }
}

void ScreenButton::handleEvent(const SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_MOUSEBUTTONDOWN:
    {
        if (_state == ButtonState_Hover)
            _state = ButtonState_Pressed;

        break;
    }

    case SDL_MOUSEBUTTONUP:
    {
        if (_state == ButtonState_Pressed &&
            event.motion.x > _dstRect.x &&
            event.motion.x < (_dstRect.x + _dstRect.w) &&
            event.motion.y > _dstRect.y &&
            event.motion.y < (_dstRect.y + _dstRect.h)) if (_callbackFunction)
            _callbackFunction();

        _state = ButtonState_Released;
        break;
    }

    case SDL_MOUSEMOTION:
    {
        bool inside = event.motion.x > _dstRect.x &&
                      event.motion.x < (_dstRect.x + _dstRect.w) &&
                      event.motion.y > _dstRect.y &&
                      event.motion.y < (_dstRect.y + _dstRect.h);

        if (inside && _state != ButtonState_Pressed)
            _state = ButtonState_Hover;
        else if (_state == ButtonState_Released || !inside)
            _state = ButtonState_Released;

        break;
    }
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

void ScreenButton::setCallback(std::function<void()> callback)
{
    _callbackFunction = callback;
}

void ScreenButton::setTexture(SDL_Texture *texture)
{
    Entity::setTexture( texture );
    _dstRect.w = width();
    _dstRect.h = height() / 3;
}
