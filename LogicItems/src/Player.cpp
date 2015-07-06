//
// Created by megaxela on 26.06.15.
//

#include "Player.h"

Player::Player() :
    PhysicsEntity(nullptr)
{
    setSpeed(2);
}

Player::Player(SDL_Renderer *renderer, const Vector2 &position) :
    PhysicsEntity(renderer)
{
    setPosition(position);
}

Player::~Player()
{

}

void Player::render()
{
    if (!camera())
    {
        printf("[Player::render] Error: Can't render player. Can't calculate position. No camera set.\n");
        return;
    }

    Entity::render();

    SDL_Rect rect;
    rect.x = position().intX() - camera()->x();
    rect.y = position().intY() - camera()->y();
    rect.w = (Uint16) width();
    rect.h = (Uint16) height();

    SDL_RenderCopy( renderer(), texture(), NULL, &rect);
}
