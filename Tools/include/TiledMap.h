//
// Created by megaxela on 20.06.15.
//

#ifndef GRAPHICS_SYSTEM_TILEDMAP_H
#define GRAPHICS_SYSTEM_TILEDMAP_H

#include <string>
#include <ResourceHolder.h>
#include "tinyxml2.h"
#include <fstream>
#include <vector>

class TiledMap
{
public:
    TiledMap();
    TiledMap(const std::string &path, ResourceHolder *holder=nullptr);
    ~TiledMap();

    ResourceHolder* resourceHolder() const;
    void setResourceHolder(ResourceHolder* holder);

    bool loadMap( const std::string &path);

private:
    /*
     * Приватные классы.
     */
    class Tileset
    {
    public:
        Tileset(
                const std::string &path,
                unsigned int tileWidth,
                unsigned int tileHeight,
                unsigned int startId = 0,
                ResourceHolder *holder=nullptr
        );
        ~Tileset();

        ResourceHolder* resourceHolder() const;
        void setResourceHolder(ResourceHolder* holder);

        void loadImage( const std::string &path );

        SDL_Texture* texture() const;

        SDL_Rect getTileSourceRect( unsigned int id );
    private:
        // Длина и ширина тайла
        unsigned int _tileWidth;
        unsigned int _tileHeight;

        // Количество тайлов
        unsigned int _numberTilesX;
        unsigned int _numberTilesY;

        unsigned int _startId;

        // Сервисные данные
        ResourceHolder *_resourceHolder;
        SDL_Texture *_texture;
    };

    class TileLayer
    {
    public:
        TileLayer();
        ~TileLayer();

        bool setData( const std::string &data, bool compression=true, bool encoding=true);

    private:
        SDL_Texture *_layerTexture;
    };
    /*
     * Приватные функции.
     */

    /*
     * Функции закрузки карты.
     */
    std::string loadingOpeningFile( const std::string &path);
    std::string loadingDecoding( const std::string &data );
    bool loadingParsing ( const std::string &data );

    /*
     * Функции обработки файла карты
     */
    bool processMapMetadata( tinyxml2::XMLElement *mapNode );
    bool processTileset( tinyxml2::XMLElement *tilesetNode );

    /*
     * Приватные члены.
     */

    std::vector < TiledMap::Tileset> _tilesets;

    ResourceHolder *_resourceHolder;
};


#endif //GRAPHICS_SYSTEM_TILEDMAP_H
