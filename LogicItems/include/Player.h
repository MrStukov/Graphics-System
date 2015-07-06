//
// Created by megaxela on 26.06.15.
//

#ifndef GRAPHICS_SYSTEM_PLAYER_H
#define GRAPHICS_SYSTEM_PLAYER_H

#include "PhysicsEntity.h"
#include "Vector2.h"
#include "Colliders.h"

class Player : public PhysicsEntity
{
public:


    Player();
    Player(SDL_Renderer *renderer, const Vector2 &position);
    ~Player();

    virtual void render() override;
};


#endif //GRAPHICS_SYSTEM_PLAYER_H
