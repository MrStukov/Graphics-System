//
// Created by megaxela on 26.06.15.
//

#ifndef GRAPHICS_SYSTEM_PLAYER_H
#define GRAPHICS_SYSTEM_PLAYER_H

#include "Vector2.h"
#include "Colliders.h"
#include "Entity.h"

class Player : public Entity
{
public:
    enum Direction
    {
        Direction_Top,
        Direction_Right,
        Direction_Left,
        Direction_Bottom
    };

    Player();
    Player(SDL_Renderer *renderer, const Vector2 &position);
    ~Player();

    void setSpeed(float speed);
    float speed() const;

    // TODO: Убрать заглушку в процессе реализации логики

    virtual void render() override;

    void move(Direction dir);

    Colliders::Rectangle getCollider() const;
private:
    float _speed;
};


#endif //GRAPHICS_SYSTEM_PLAYER_H
