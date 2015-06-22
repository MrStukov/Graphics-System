//
// Created by megaxela on 22.06.15.
//

#include "Colliders.h"

Colliders::Rectangle::Rectangle()
{
    _x = 0;
    _y = 0;
    _width = 0;
    _height = 0;
}

Colliders::Rectangle::Rectangle(int x, int y, unsigned int w, unsigned int h)
{
    setPosition(x, y);
    setSize(w, h);
}

Colliders::Rectangle::~Rectangle()
{

}

void Colliders::Rectangle::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

int Colliders::Rectangle::x() const
{
    return _x;
}

int Colliders::Rectangle::y() const
{
    return _y;
}

void Colliders::Rectangle::setSize(unsigned int w, unsigned int h)
{
    _width = w;
    _height = h;
}

unsigned int Colliders::Rectangle::width() const
{
    return _width;
}

unsigned int Colliders::Rectangle::height() const
{
    return _height;
}

bool Colliders::Rectangle::operator==(Colliders::Rectangle const &b) const
{
    return b._x == _x && b._y == _y && b._width == _width && b._height == _height;
}

bool ::Colliders::isColliding(Colliders::Rectangle const &a, Colliders::Rectangle const &b)
{
    // TODO: Добавить реализацию пересечения.
    return false;
}
