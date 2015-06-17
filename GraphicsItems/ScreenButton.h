//
// Created by megaxela on 17.06.15.
//

#ifndef GRAPHICS_SYSTEM_SCREENBUTTON_H
#define GRAPHICS_SYSTEM_SCREENBUTTON_H

#include <SDL2/SDL.h>

//TODO: Добавить вызываемую ф-цию.
class ScreenButton
{
public:
    ScreenButton();
    ScreenButton(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, unsigned int w, unsigned int h);
    ~ScreenButton();

    void setRenderer(SDL_Renderer *renderer);
    SDL_Renderer *renderer() const;

    void setTexture(SDL_Texture *texture);
    SDL_Texture *texture() const;

    void render();
    void update(float deltaTime);
    void handleEvent(SDL_Event *event);

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
    SDL_Renderer *_renderer;
};


#endif //GRAPHICS_SYSTEM_SCREENBUTTON_H
