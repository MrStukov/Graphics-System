//
// Created by megaxela on 17.06.15.
//

#ifndef GRAPHICS_SYSTEM_SCREENBUTTON_H
#define GRAPHICS_SYSTEM_SCREENBUTTON_H

#include <SDL2/SDL.h>
#include <functional>
#include "ScreenItem.h"

//TODO: Добавить Collider вместо явной проверки.
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
    ScreenButton(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, std::function<void()> callback);
    ~ScreenButton();

    void setTexture(SDL_Texture *texture);
    SDL_Texture *texture() const;

    void setPosition(int x, int y);
    int x() const;
    int y() const;

    void render();
    void handleEvent(const SDL_Event &event);

    void setCallback( std::function<void()> function );

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

    std::function<void()> _callbackFunction;
};


#endif //GRAPHICS_SYSTEM_SCREENBUTTON_H
