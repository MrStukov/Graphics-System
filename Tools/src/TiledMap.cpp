//
// Created by megaxela on 20.06.15.
//

#include "TiledMap.h"

TiledMap::Tileset::Tileset(const std::string &path, unsigned int tileWidth, unsigned int tileHeight,
                                       unsigned int startId, ResourceHolder *holder)
{
    _tileWidth = tileWidth;
    _tileHeight = tileHeight;
    _resourceHolder = holder;
    _startId = startId;

    _texture = nullptr;
    loadImage( path );
}

TiledMap::Tileset::~Tileset()
{

}

ResourceHolder *TiledMap::Tileset::resourceHolder() const
{
    return _resourceHolder;
}

void TiledMap::Tileset::setResourceHolder(ResourceHolder *holder)
{
    _resourceHolder = holder;
}

void TiledMap::Tileset::loadImage(const std::string &path)
{
    // TODO: Добавить реализацию
}

SDL_Texture *TiledMap::Tileset::texture() const
{
    return _texture;
}

SDL_Rect TiledMap::Tileset::getTileSourceRect(unsigned int id)
{
    // TODO: Добавить реализацию
    return SDL_Rect();
}

TiledMap::TiledMap()
{
    _resourceHolder = nullptr;
}

TiledMap::TiledMap(std::string const &path, ResourceHolder *holder)
{
    // TODO: Заменить printf на logger
    setResourceHolder(holder);
    if (!loadMap(path))
        printf("[TiledMap::TiledMap] Error: Can't load map.\n");
}

TiledMap::~TiledMap()
{

}

ResourceHolder *TiledMap::resourceHolder() const
{
    return _resourceHolder;
}

void TiledMap::setResourceHolder(ResourceHolder *holder)
{
    _resourceHolder = holder;
}

bool TiledMap::loadMap(const std::string &path)
{
    std::string fileData = loadingOpeningFile(path);
    if (fileData.length() <= 0)
    {
        printf("[TiledMap::loadMap] Error: Can't open map file.\n");
        return false;
    }

    std::string decodedFile = loadingDecoding(fileData);
    if (decodedFile.length() <= 0)
    {
        printf("[TiledMap::loadMap] Error: Can't decode map file.\n");
        return false;
    }

    bool parsingResult = loadingParsing( decodedFile );
    if (!parsingResult)
        printf("[TiledMap::loadMap] Error: Can't parse map file.\n");

    return parsingResult;
}

std::string TiledMap::loadingOpeningFile(const std::string &path)
{
    std::string fileData;
    std::string line;
    std::ifstream fl(path);
    if (fl.is_open())
    {
        while (getline(fl, line))
            fileData += line + "\n";
        return fileData;
    }
    else
        return std::string();
}

std::string TiledMap::loadingDecoding(const std::string &data)
{
    // TODO: Добавить реализанию декодирования файла.
    return data;
}

bool TiledMap::loadingParsing(const std::string &data)
{
    tinyxml2::XMLDocument document;
    tinyxml2::XMLError error;

    error = document.Parse(data.c_str(), data.length());
    if (error != tinyxml2::XML_NO_ERROR)
        return false;

    tinyxml2::XMLElement *tilesetElement = document.FirstChildElement("tileset");
    while (tilesetElement)
    {
        // Обработка тайлсетов
        if (!processTileset(tilesetElement))
        {
            printf("[TiledMap::loadingParsing] Error: Can't load tileset.\n");
            return false;
        }
        tilesetElement = tilesetElement->NextSiblingElement("tileset");
    }

    // TODO: Закончить обработку файла с картой.
}

bool TiledMap::processMapMetadata(tinyxml2::XMLElement *mapNode)
{
    // TODO: Добавить обработку метаданных.
    return true;
}

bool TiledMap::processTileset(tinyxml2::XMLElement *tilesetNode)
{
    // Проверка на указатель
    if (!tilesetNode)
    {
        printf("[TiledMap::processTileset] Error: Tileset processor was started with null pointer.\n");
        return false;
    }

    tinyxml2::XMLElement *imageNode = tilesetNode->FirstChildElement("image");
    if (!imageNode)
    {
        printf("[TiledMap::processTileset] Error: Image element was not found.\n");
        return false;
    }

    // TODO: Добавить стандартный аргумент для source.
    _tilesets.push_back( Tileset(
        imageNode->Attribute("source", ""),
        (unsigned int) atoi(tilesetNode->Attribute("tilewidth", "32")),
        (unsigned int) atoi(tilesetNode->Attribute("tileheight", "32")),
        (unsigned int) atoi(tilesetNode->Attribute("firstgid", "0")),
        _resourceHolder
    ));

    return true;
}
