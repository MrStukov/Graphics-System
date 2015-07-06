//
// Created by megaxela on 22.06.15.
//

#include "Colliders.h"

bool Colliders::RectangleCollider::operator==(Colliders::RectangleCollider const &b) const
{
    return b.x == x && b.y == y && b.width == width && b.height == height;
}

bool ::Colliders::isColliding(Colliders::RectangleCollider const &a, Colliders::RectangleCollider const &b)
{
    // Обратная проверка.
    return !((a.x >= b.x + b.width) ||
             (a.y >= b.y + b.height) ||
             (a.x + a.width <= b.x) ||
             (a.y + a.height <= b.y));
}

bool ::Colliders::isColliding(const Colliders::RectangleCollider &a, const Colliders::PointCollider &b)
{
    return !((b.x >= a.x + a.width) ||
             (b.y >= a.y + a.width) ||
             (b.x <= a.x) ||
             (b.y <= a.y));
}

bool ::Colliders::isColliding(const Colliders::PointCollider &a, const Colliders::RectangleCollider &b)
{
    return !((a.x >= b.x + b.width) ||
             (a.y >= b.y + b.width) ||
             (a.x <= b.x) ||
             (a.y <= b.y));
}

Colliders::CollisionController::CollisionController()
{

}

Colliders::CollisionController::~CollisionController()
{

}

bool Colliders::CollisionController::isColliding(Colliders::RectangleCollider const &a) const
{
    bool colliding = false;
    for (std::vector<Colliders::RectangleCollider>::const_iterator iterator = _rectangles.begin();
         iterator != _rectangles.end() && !colliding;
         iterator++)
        if (Colliders::isColliding((*iterator), a))
            colliding = true;

    return colliding;
}

bool Colliders::CollisionController::isColliding(Colliders::PointCollider const &a) const
{
    bool colliding = false;
    for (std::vector<Colliders::RectangleCollider>::const_iterator iterator = _rectangles.begin();
         iterator != _rectangles.end() && !colliding;
         iterator++)
        if (Colliders::isColliding((*iterator), a))
            colliding = true;

    return colliding;
}


void Colliders::CollisionController::addCollider(Colliders::RectangleCollider const &rectangle)
{
    _rectangles.push_back(rectangle);
}

void Colliders::CollisionController::clear()
{
    _rectangles.clear();
}

Colliders::RectangleCollider Colliders::RectangleCollider::margin(int margin, Direction dir) const
{
    Colliders::RectangleCollider newRect = (*this);

    if (dir == Direction_Left || dir == Direction_All)
        newRect.x -= margin;


    if (dir == Direction_Top || dir == Direction_All)
        newRect.y -= margin;

    if (dir == Direction_All)
    {
        newRect.width += margin * 2;
        newRect.height += margin * 2;
    }

    if (dir == Direction_Right)
        newRect.width += margin;

    if (dir == Direction_Bottom)
        newRect.height += margin;

    return newRect;
}

const std::vector<Colliders::RectangleCollider> &Colliders::CollisionController::rectColliders() const
{
    return _rectangles;
}
