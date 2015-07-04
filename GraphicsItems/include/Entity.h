//
// Created by megaxela on 04.07.15.
//

#ifndef GRAPHICS_SYSTEM_ENTITY_H
#define GRAPHICS_SYSTEM_ENTITY_H

#include <SDL2/SDL.h>
#include "Vector2.h"
#include "Camera.h"

class Entity
{
public:
    Entity( SDL_Renderer *renderer=nullptr );
    virtual ~Entity();

    void setRenderer( SDL_Renderer *renderer );
    SDL_Renderer *renderer() const;

    void setPosition(const Vector2 &position);
    Vector2 position() const;

    unsigned int width() const;
    unsigned int height() const;

    // TODO: Добавить проверку статуса ф-ции SDL_QueryTexture
    void setTexture( SDL_Texture *texture );
    SDL_Texture *texture() const;

    void setCamera( Camera *camera );
    Camera* camera() const;

    virtual void update( float deltaTime );
    virtual void render();
    virtual void handleEvent( SDL_Event *event );
private:
    Vector2 _position;
    unsigned int _width;
    unsigned int _height;

    SDL_Renderer *_renderer;
    Camera *_camera;
    SDL_Texture *_texture;
};


#endif //GRAPHICS_SYSTEM_ENTITY_H
