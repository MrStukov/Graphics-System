//
// Created by megaxela on 22.06.15.
//

#ifndef GRAPHICS_SYSTEM_COLLIDERS_H
#define GRAPHICS_SYSTEM_COLLIDERS_H


namespace Colliders
{
    class Rectangle
    {
    public:
        Rectangle();
        Rectangle( int x, int y, unsigned int w, unsigned int h);
        ~Rectangle();

        void setPosition( int x, int y );

        int x() const;
        int y() const;

        void setSize (unsigned int w, unsigned int h);

        unsigned int width() const;
        unsigned int height() const;

        bool operator==(const Rectangle &b) const;
        
    private:
        int _x;
        int _y;
        unsigned int _width;
        unsigned int _height;
    };

    bool isColliding( const Rectangle& a, const Rectangle& b);
};


#endif //GRAPHICS_SYSTEM_COLLIDERS_H
