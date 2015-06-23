//
// Created by megaxela on 22.06.15.
//

#ifndef GRAPHICS_SYSTEM_COLLIDERS_H
#define GRAPHICS_SYSTEM_COLLIDERS_H

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

    bool isColliding( const Rectangle& a, const Rectangle &b );
    bool isColliding( const Rectangle& a, const Point &b );
    bool isColliding( const Point &a, const Rectangle &b );
};


#endif //GRAPHICS_SYSTEM_COLLIDERS_H
