//
// Created by megaxela on 18.06.15.
//

#ifndef GRAPHICS_SYSTEM_SCREENITEM_H
#define GRAPHICS_SYSTEM_SCREENITEM_H

#include <SDL2/SDL.h>

class ScreenItem
{
public:
    ScreenItem(SDL_Renderer *renderer=nullptr);
    virtual ~ScreenItem();

    void setRenderer( SDL_Renderer *renderer );
    SDL_Renderer *renderer() const;

    virtual void update( float deltaTime );
    virtual void render();
    virtual void handleEvent( SDL_Event *event );

protected:
    SDL_Renderer *_renderer;
};


#endif //GRAPHICS_SYSTEM_SCREENITEM_H
