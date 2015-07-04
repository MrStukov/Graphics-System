#ifndef VECTOR2_H
#define VECTOR2_H

#include <cstdio>
#include <SDL2/SDL.h>
#include <initializer_list>
#include "math.h"
#include <algorithm>


//TODO: Добавить документацию, плюс добавить ф-цию toString
class Vector2
{
    public:
        Vector2();
        Vector2(float x, float y);
        Vector2(std::initializer_list<float> initializerList);
        virtual ~Vector2();

        float x() const;
        float y() const;

        int intX() const;
        int intY() const;

        void setX(float xPos);
        void setY(float yPos);

        Vector2 operator + (const Vector2& b);
        Vector2 operator - (const Vector2& b);
        Vector2 operator * (const Vector2& b);
        Vector2 operator * (const float &b);
        //int не нужен, так как все равно он преобразуется во float

        Vector2& operator += (const Vector2& b);
        Vector2& operator *= (const Vector2& b);
        Vector2& operator /= (const Vector2& b);
        Vector2& operator -= (const Vector2& b);

        //Vector2& operator = (const int& b);

        void print() const;
        bool isInside(const SDL_Rect* rct, bool side=false) const;

        void LerpTo(const Vector2 &to, float t);
        static Vector2 Lerp(const Vector2 &from, const Vector2 &to, float t );
    protected:
    private:
        float _x;
        float _y;
};

#endif // VECTOR2_H
