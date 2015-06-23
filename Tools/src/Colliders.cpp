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
