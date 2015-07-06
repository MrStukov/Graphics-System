//
// Created by megaxela on 22.06.15.
//

#ifndef GRAPHICS_SYSTEM_COLLIDERS_H
#define GRAPHICS_SYSTEM_COLLIDERS_H

#include <vector>
#include <algorithm>

namespace Colliders
{
    enum Direction
    {
        Direction_Top,
        Direction_Left,
        Direction_Right,
        Direction_Bottom,
        Direction_All
    };

    struct RectangleCollider
    {

        int x;
        int y;
        unsigned int width;
        unsigned int height;

        RectangleCollider(int x, int y, unsigned int width, unsigned int height) :
                x(x), y(y), width(width), height(height)
        { }

        bool operator==(const RectangleCollider &b) const;
        RectangleCollider margin( int margin, Direction dir=Direction_All ) const;
    };

    struct PointCollider
    {
        int x;
        int y;
    };

    class CollisionController
    {
    // TODO: Добавить разделение на несколько массивов для того, что бы не обрабатывать много данных.
    public:
        CollisionController();
        ~CollisionController();

        void clear();

        bool isColliding( const RectangleCollider &a ) const;
        bool isColliding( const PointCollider &a ) const;

        void addCollider( const RectangleCollider &rectangle );

        const std::vector < Colliders::RectangleCollider> &rectColliders() const;
    private:
        std::vector < Colliders::RectangleCollider> _rectangles;
    };

    bool isColliding( const RectangleCollider & a, const RectangleCollider &b );
    bool isColliding( const RectangleCollider & a, const PointCollider &b );
    bool isColliding( const PointCollider &a, const RectangleCollider &b );
};


#endif //GRAPHICS_SYSTEM_COLLIDERS_H
