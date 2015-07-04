//
// Created by megaxela on 22.06.15.
//

#ifndef GRAPHICS_SYSTEM_COLLIDERS_H
#define GRAPHICS_SYSTEM_COLLIDERS_H

#include <vector>
#include <algorithm>

namespace Colliders
{
    struct Rectangle
    {
        int x;
        int y;
        unsigned int width;
        unsigned int height;

        bool operator==(const Rectangle &b) const;
    };

    struct Point
    {
        int x;
        int y;
    };

    class CollidersHolder
    {
    // TODO: Добавить разделение на несколько массивов для того, что бы не обрабатывать много данных.
    public:
        CollidersHolder();
        ~CollidersHolder();

        void clear();

        bool isColliding( const Rectangle &a ) const;
        bool isColliding( const Point &a ) const;

        void addCollider( const Rectangle &rectangle );

    private:
        std::vector < Colliders::Rectangle > _rectangles;
    };

    bool isColliding( const Rectangle& a, const Rectangle &b );
    bool isColliding( const Rectangle& a, const Point &b );
    bool isColliding( const Point &a, const Rectangle &b );
};


#endif //GRAPHICS_SYSTEM_COLLIDERS_H
