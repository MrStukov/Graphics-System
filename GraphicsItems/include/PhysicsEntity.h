//
// Created by megaxela on 06.07.15.
//

#ifndef GRAPHICS_SYSTEM_PHYSICSENTITY_H
#define GRAPHICS_SYSTEM_PHYSICSENTITY_H

#include <Subscriber.h>
#include <Colliders.h>
#include "Entity.h"

class PhysicsEntity : public Entity
{
public:
    enum Direction
    {
        Direction_Top,
        Direction_Right,
        Direction_Left,
        Direction_Bottom
    };

    PhysicsEntity( SDL_Renderer *renderer=nullptr );
    virtual ~PhysicsEntity();

    Subscriber<Colliders::CollisionController> * getCollisionSubscriber() const;
    void setCollisionSubscriber(Subscriber<Colliders::CollisionController> *collisionSubscriber);

    float speed() const;
    void setSpeed(float speed);

    Colliders::RectangleCollider getCollider() const;

    virtual void move(Direction dir);

    void renderCollider( int x, int y ) const;
private:
    Subscriber< Colliders::CollisionController > *_collisionSubscriber;

    float _speed;
};


#endif //GRAPHICS_SYSTEM_PHYSICSENTITY_H
