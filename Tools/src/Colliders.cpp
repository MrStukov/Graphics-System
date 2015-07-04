//
// Created by megaxela on 22.06.15.
//

#include "Colliders.h"

bool Colliders::Rectangle::operator==(Colliders::Rectangle const &b) const
{
    return b.x == x && b.y == y && b.width == width && b.height == height;
}

bool ::Colliders::isColliding(Colliders::Rectangle const &a, Colliders::Rectangle const &b)
{
    // Обратная проверка.
    return !((a.x > b.x + b.width) ||
             (a.y > b.y + b.height) ||
             (a.x + a.width < b.x) ||
             (a.y + a.height < b.y));
}

bool ::Colliders::isColliding(const Colliders::Rectangle &a, const Colliders::Point &b)
{
    return !((b.x > a.x + a.width) ||
             (b.y > a.y + a.width) ||
             (b.x < a.x) ||
             (b.y < a.y));
}

bool ::Colliders::isColliding(const Colliders::Point &a, const Colliders::Rectangle &b)
{
    return !((a.x > b.x + b.width) ||
             (a.y > b.y + b.width) ||
             (a.x < b.x) ||
             (a.y < b.y));
}

Colliders::CollidersHolder::CollidersHolder()
{

}

Colliders::CollidersHolder::~CollidersHolder()
{

}

bool Colliders::CollidersHolder::isColliding(Colliders::Rectangle const &a) const
{
    bool colliding = false;
    for (std::vector<Colliders::Rectangle>::const_iterator iterator = _rectangles.begin();
         iterator != _rectangles.end() && !colliding;
         iterator++)
        if (Colliders::isColliding((*iterator), a))
            colliding = true;

    return colliding;
}

bool Colliders::CollidersHolder::isColliding(Colliders::Point const &a) const
{
    bool colliding = false;
    for (std::vector<Colliders::Rectangle>::const_iterator iterator = _rectangles.begin();
         iterator != _rectangles.end() && !colliding;
         iterator++)
        if (Colliders::isColliding((*iterator), a))
            colliding = true;

    return colliding;
}


void Colliders::CollidersHolder::addCollider(Colliders::Rectangle const &rectangle)
{
    _rectangles.push_back(rectangle);
}

void Colliders::CollidersHolder::clear()
{
    _rectangles.clear();
}
