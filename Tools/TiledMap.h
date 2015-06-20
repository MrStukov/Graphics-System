//
// Created by megaxela on 20.06.15.
//

#ifndef GRAPHICS_SYSTEM_TILEDMAP_H
#define GRAPHICS_SYSTEM_TILEDMAP_H

#include <string>
#include <ResourceHolder.h>

class TiledMap
{
public:
    TiledMap(const std::string &path, ResourceHolder *holder=nullptr);
    ~TiledMap();

    ResourceHolder* resourceHolder() const;
    void setResourceHolder(ResourceHolder* holder);

private:

    /*
     * Приватные классы.
     */
    class Tiled_Tileset
    {
    public:
        Tiled_Tileset(
                const std::string &path,
                unsigned int tileWidth,
                unsigned int tileHeight,
                unsigned int startId = 0,
                ResourceHolder *holder=nullptr
        );
        ~Tiled_Tileset();

        ResourceHolder* resourceHolder() const;
        void setResourceHolder(ResourceHolder* holder);

        void loadImage( const std::string &path );

    private:
        unsigned int _tileWidth;
        unsigned int _tileHeight;

        unsigned int _numberTilesX;
        unsigned int _numberTilesY;

        ResourceHolder *_holder;
        SDL_Texture *_texture;

    };

    /*
     * Приватные члены.
     */
    ResourceHolder *_holder;
};


#endif //GRAPHICS_SYSTEM_TILEDMAP_H
