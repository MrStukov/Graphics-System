//
// Created by megaxela on 06.07.15.
//

#include "PhysicsEntity.h"

PhysicsEntity::PhysicsEntity(SDL_Renderer *renderer) :
        Entity(renderer)
{

}

PhysicsEntity::~PhysicsEntity()
{

}

Subscriber<Colliders::CollisionController> *PhysicsEntity::getCollisionSubscriber() const
{
    return _collisionSubscriber;
}

void PhysicsEntity::setCollisionSubscriber(Subscriber<Colliders::CollisionController> *collisionSubscriber)
{
    PhysicsEntity::_collisionSubscriber = collisionSubscriber;
}

float PhysicsEntity::speed() const
{
    return _speed;
}

void PhysicsEntity::setSpeed(float speed)
{
    PhysicsEntity::_speed = speed;
}

void PhysicsEntity::move(PhysicsEntity::Direction dir)
{
    Colliders::RectangleCollider collider = getCollider();

    switch (dir)
    {
    case Direction_Top:
        if (_collisionSubscriber->value()->isColliding(collider.margin((int) speed(), Colliders::Direction_Top)))
        {
            for (int allowedMargin = (int) speed();
                 allowedMargin >= 0;
                 allowedMargin--)
            {
                if (!_collisionSubscriber->value()->isColliding(
                        collider.margin(allowedMargin, Colliders::Direction_Top)))
                {
                    setPosition(position() + Vector2(0, -allowedMargin));
                    break;
                }
            }
        }
        else
            setPosition(position() + Vector2(0, -speed()));
        break;
    case Direction_Right:
        if (_collisionSubscriber->value()->isColliding(collider.margin((int) speed(), Colliders::Direction_Right)))
        {
            for (int allowedMargin = (int) speed();
                 allowedMargin >= 0;
                 allowedMargin--)
            {
                if (!_collisionSubscriber->value()->isColliding(
                        collider.margin(allowedMargin, Colliders::Direction_Right)))
                {
                    setPosition(position() + Vector2(allowedMargin, 0));
                    break;
                }
            }
        }
        else
            setPosition(position() + Vector2(speed(), 0));
        break;
    case Direction_Left:
        if (_collisionSubscriber->value()->isColliding(collider.margin((int) speed(), Colliders::Direction_Left)))
        {
            for (int allowedMargin = (int) speed();
                 allowedMargin >= 0;
                 allowedMargin--)
            {
                if (!_collisionSubscriber->value()->isColliding(
                        collider.margin(allowedMargin, Colliders::Direction_Left)))
                {
                    setPosition(position() + Vector2(-allowedMargin, 0));
                    break;
                }
            }
        }
        else
            setPosition(position() + Vector2(-speed(), 0));
        break;
    case Direction_Bottom:
        if (_collisionSubscriber->value()->isColliding(collider.margin((int) speed(), Colliders::Direction_Bottom)))
        {
            for (int allowedMargin = (int) speed();
                 allowedMargin >= 0;
                 allowedMargin--)
            {
                if (!_collisionSubscriber->value()->isColliding(
                        collider.margin(allowedMargin, Colliders::Direction_Bottom)))
                {
                    setPosition(position() + Vector2(0, allowedMargin));
                    break;
                }
            }
        }
        else
            setPosition(position() + Vector2(0, speed()));
        break;
    }
}

Colliders::RectangleCollider PhysicsEntity::getCollider() const
{
    return Colliders::RectangleCollider(
            position().intX(),
            position().intY(),
            width(),
            height()
    );
}

void PhysicsEntity::renderCollider(int x, int y) const
{
    Colliders::RectangleCollider collider = getCollider();

    SDL_Rect srcRect = {
            collider.x + x,
            collider.y + y,
            collider.width,
            collider.height
    };
    SDL_RenderDrawRect(renderer(), &srcRect);
}
