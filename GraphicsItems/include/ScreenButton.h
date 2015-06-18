//
// Created by megaxela on 17.06.15.
//

#ifndef GRAPHICS_SYSTEM_SCREENBUTTON_H
#define GRAPHICS_SYSTEM_SCREENBUTTON_H

#include <SDL2/SDL.h>
#include "ScreenItem.h"

//TODO: Добавить вызываемую ф-цию.
/*
 * Класс экранной кнопки. Обрабатывает нажатие мышью.
 * Наследуется от асбтрактного класса ScreenItem.
 *
 * Передается текстура, состоящая из 3 кнопок.
 * Сверху - вниз:
 *      Release
 *      Hover
 *      Pressed
 */
class ScreenButton : public ScreenItem
{
public:
    ScreenButton();
    ScreenButton(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, void (*callBack)());
    ~ScreenButton();

    void setTexture(SDL_Texture *texture);
    SDL_Texture *texture() const;

    void setPosition(int x, int y);
    int x() const;
    int y() const;

    void render();
    void handleEvent(SDL_Event *event);

    void setCallback( void (*callback)() );

private:
    enum ButtonState
    {
        ButtonState_Released,
        ButtonState_Hover,
        ButtonState_Pressed
    };

    ButtonState _state;

    SDL_Rect _dstRect;

    SDL_Texture *_texture;
    int _textureWidth;
    int _textureHeight;

    void (*_callbackFunction)();

    SDL_Renderer *_renderer;
};


#endif //GRAPHICS_SYSTEM_SCREENBUTTON_H
