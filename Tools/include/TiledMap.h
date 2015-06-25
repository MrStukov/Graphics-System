//
// Created by megaxela on 20.06.15.
//

#ifndef GRAPHICS_SYSTEM_TILEDMAP_H
#define GRAPHICS_SYSTEM_TILEDMAP_H

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "ResourceHolder.h"
#include "tinyxml2.h"
#include "Compression.h"

// TODO: Добавить рендер с предусмотрением неполного рендеринга

class TiledMap
{
public:
    TiledMap();
    TiledMap(const std::string &path, ResourceHolder *holder=nullptr);
    ~TiledMap();

    ResourceHolder* resourceHolder() const;
    void setResourceHolder(ResourceHolder* holder);

    bool loadMap( const std::string &path);

    bool renderLower(SDL_Renderer* _renderer, int x, int y);
    bool renderUpper(SDL_Renderer* _renderer, int x, int y);

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

        bool loadImage( const std::string &path );

        SDL_Texture* texture() const;

        SDL_Rect getTileSourceRect( unsigned int id );
        bool containsId( unsigned int id ) const;

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
        TileLayer(ResourceHolder *holder=nullptr);
        ~TileLayer();

        bool setData( std::string data, bool compression=true, bool encoding=true);

        void render( SDL_Renderer *renderer, int x, int y );

        void clear();

        void setResourceHolder( ResourceHolder *holder );
        ResourceHolder *resourceHolder() const;

        void setSize( unsigned int width, unsigned int height );

        void setWidth( unsigned int width );
        unsigned int width() const;

        void setHeight( unsigned int height );
        unsigned int height() const;

        void setTileSize( unsigned int tileWidth, unsigned tileHeight );

        void setTileWidth( unsigned int tileWidth );
        unsigned int tileWidth() const;

        void setTileHeight( unsigned int tileHeight );
        unsigned int tileHeight() const;

        void setTilesets( std::vector < TiledMap::Tileset > *tilesets );
        std::vector < TiledMap::Tileset > *tilesets() const;

    private:
        struct TileData
        {
            unsigned int id;
            unsigned int tilesetIndex;
        };

        unsigned int _tileWidth;
        unsigned int _tileHeight;

        unsigned int _width;
        unsigned int _height;

        ResourceHolder *_resourceHolder;
        std::vector < Tileset > *_tilesets;

        std::vector < TileData > _data;
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
    bool processTileLayer( tinyxml2::XMLElement *tileLayerNode );

    /*
     * Приватные члены.
     */
    unsigned int _xSize;
    unsigned int _ySize;

    unsigned int _tileWidth;
    unsigned int _tileHeight;

    std::vector < TiledMap::Tileset> _tilesets;
    std::vector < TiledMap::TileLayer > _tileLayers;

    ResourceHolder *_resourceHolder;
};


#endif //GRAPHICS_SYSTEM_TILEDMAP_H
