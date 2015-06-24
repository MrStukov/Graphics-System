#include "Vector2.h"



Vector2::Vector2()
{
    _x = 0;
    _y = 0;
}

Vector2::Vector2(float x, float y)
{
    _x = x;
    _y = y;
}

Vector2::~Vector2()
{
    //dtor
}

float Vector2::x() const
{
    return _x;
}

float Vector2::y() const
{
    return _y;
}

void Vector2::setX(float xPos)
{
    _x = xPos;
}

void Vector2::setY(float yPos)
{
    _y = yPos;
}

Vector2 Vector2::operator+ (const Vector2& b)
{
    /*
    _x += b._x;
    _y += b._y;

    return *this;
    */

    return Vector2(_x + b._x, _y + b._y);
}

Vector2 Vector2::operator- (const Vector2& b)
{
    return Vector2(_x - b._x, _y - b._y);
}

Vector2 Vector2::operator* (const Vector2& b)
{
    return Vector2(_x * b._x, _y * b._y);
}

Vector2 Vector2::operator* (const float &b)
{
    return Vector2(_x * b, _y * b);
}

Vector2& Vector2::operator+=(const Vector2& b)
{
    _x += b._x;
    _y += b._y;

    return *this;
}

Vector2& Vector2::operator-=(const Vector2& b)
{
    _x -= b._x;
    _y -= b._y;

    return *this;
}

Vector2& Vector2::operator*=(const Vector2& b)
{
    _x *= b._x;
    _y *= b._y;

    return *this;
}

Vector2& Vector2::operator/=(const Vector2& b)
{
    _x /= b._x;
    _y /= b._y;

    return *this;
}
/*
Vector2& Vector2::operator=(const int& b)
{
    _x = b;
    _y = b;

    return *this;
}
*/


void Vector2::print() const
{
    printf("Vector2(%f, %f)\n", _x, _y);
}

bool Vector2::isInside(const SDL_Rect* rct, bool side) const
{
    if (side)
        return (_x >= rct->x) &&
               (_x <= (rct->x + rct->w)) &&
               (_y >= rct->y) &&
               (_y <= (rct->y + rct->h));
    else
        return (_x > rct->x) &&
               (_x < (rct->x + rct->w)) &&
               (_y > rct->y) &&
               (_y < (rct->y + rct->h));

}

float Clamp01(float value)
{
    if (value < 0)
	{
		return 0;
	}
	if (value > 1)
	{
		return 1;
	}
	return value;
}

void Vector2::LerpTo(const Vector2 &to, float t)
{
    t = Clamp01(t);
    _x = _x + (to.x() - _x) * t;
    _y = _y + (to.y() - _y) * t;
}

int Vector2::intX() const
{
    return (int) round(_x);
}

int Vector2::intY() const
{
    return (int) round(_y);
}

Vector2 Vector2::Lerp(const Vector2 &from, const Vector2 &to, float t)
{
    t = Clamp01(t);
    Vector2 result = from;

    result.LerpTo(to, t);

    return result;
}
