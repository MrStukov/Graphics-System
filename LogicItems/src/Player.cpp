//
// Created by megaxela on 26.06.15.
//

#include "Player.h"

Player::Player() :
    Entity(nullptr)
{

}

Player::Player(SDL_Renderer *renderer, const Vector2 &position) :
    Entity(renderer)
{
    setPosition(position);
}

Player::~Player()
{

}

void Player::setSpeed(float speed)
{
    _speed = speed;
}

float Player::speed() const
{
    return _speed;
}

void Player::move(Direction dir)
{
    switch (dir)
    {
    case Direction_Top:
        setPosition( position() + Vector2(0, -_speed) );
        break;
    case Direction_Right:
        setPosition( position() + Vector2(_speed, 0) );
        break;
    case Direction_Left:
        setPosition( position() + Vector2(-_speed, 0) );
        break;
    case Direction_Bottom:
        setPosition( position() + Vector2(0, _speed) );
        break;
    }
}

Colliders::Rectangle Player::getCollider() const
{
    Colliders::Rectangle rectangle;
    rectangle.x = position().intX();
    rectangle.y = position().intY();

    rectangle.width = width();
    rectangle.height = height();

    return rectangle;
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
