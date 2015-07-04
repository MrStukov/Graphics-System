//
// Created by megaxela on 17.06.15.
//

#ifndef GRAPHICS_SYSTEM_SCREENBUTTON_H
#define GRAPHICS_SYSTEM_SCREENBUTTON_H

#include <functional>
#include "Entity.h"

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

// fixme: Заменить явную передачу координат на Vector2
class ScreenButton : public Entity
{
public:
    ScreenButton();
    ScreenButton(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, std::function<void()> callback);
    ~ScreenButton();

    void setPosition(int x, int y);
    int x() const;
    int y() const;

    void render();

    // TODO: Добавить поддержку нового API с MouseHolderо.
    void handleEvent(const SDL_Event &event);

    void setCallback( std::function<void()> function );

    void setTexture( SDL_Texture *texture );

private:
    enum ButtonState
    {
        ButtonState_Released,
        ButtonState_Hover,
        ButtonState_Pressed
    };

    ButtonState _state;

    SDL_Rect _dstRect;

    std::function<void()> _callbackFunction;
};


#endif //GRAPHICS_SYSTEM_SCREENBUTTON_H
