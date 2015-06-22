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

bool TiledMap::Tileset::loadImage(const std::string &path)
{
    if (!_resourceHolder)
    {
        printf("[Tileset::loadImage] Error: Can't load image for tileset. No resource holder.\n");
        return false;
    }

    _texture = _resourceHolder->loadTexture(path);

    int width = 0;
    int height = 0;

    SDL_QueryTexture(_texture, NULL, NULL, &width, &height);

    _numberTilesX = width / _tileWidth;
    _numberTilesY = height / _tileHeight;

    return true;
}

SDL_Texture *TiledMap::Tileset::texture() const
{
    return _texture;
}

SDL_Rect TiledMap::Tileset::getTileSourceRect(unsigned int id)
{
    unsigned int resultID = id - _startId;

    unsigned int x = resultID % _numberTilesX;
    unsigned int y = resultID / _numberTilesX;

    SDL_Rect rect = {
            (int) (x * _tileWidth),
            (int) (y * _tileHeight),
            (int) _tileWidth,
            (int) _tileHeight
    };

    return rect;
}

bool TiledMap::Tileset::containsId(unsigned int id) const
{
    return !(id < _startId || id > (_startId + _numberTilesX * _numberTilesY));
}

TiledMap::TiledMap()
{
    _resourceHolder = nullptr;
    _xSize = 0;
    _ySize = 0;
    _tileWidth = 0;
    _tileHeight = 0;
}

TiledMap::TiledMap(std::string const &path, ResourceHolder *holder)
{
    // TODO: Заменить printf на logger
    _xSize = 0;
    _ySize = 0;

    _tileWidth = 0;
    _tileHeight = 0;

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

    tinyxml2::XMLElement *mapElement = document.FirstChildElement("map");
    if (!mapElement)
    {
        printf("[TiledMap::loadingParsing] Error: Can't get map node.\n");
        return false;
    }

    // Обработка метаданных
    if (!processMapMetadata( mapElement ))
    {
        printf("[TiledMap::loadingParsing] Error: Can't load map metadata.\n");
        return false;
    }

    // Заргузка тайлсетов
    tinyxml2::XMLElement *tilesetElement = mapElement->FirstChildElement("tileset");
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

    // Загрузка слоев с тайлами
    tinyxml2::XMLElement *tileLayerElement = mapElement->FirstChildElement("layer");
    while (tileLayerElement)
    {
        if (!processTileLayer(tileLayerElement))
        {
            printf("[TiledMap::loadingParsing] Error: Can't load tile layer: %s\n",
                   tileLayerElement->Attribute("name"));
            return false;
        }
        tileLayerElement = tileLayerElement->NextSiblingElement("layer");
    }

    // TODO: Закончить обработку файла с картой.
    return true;
}

bool TiledMap::processMapMetadata(tinyxml2::XMLElement *mapNode)
{
    _xSize = (unsigned int) atoi( mapNode->Attribute("width") );
    _ySize = (unsigned int) atoi( mapNode->Attribute("height") );

    _tileWidth = (unsigned int) atoi( mapNode->Attribute("tilewidth") );
    _tileHeight = (unsigned int) atoi( mapNode->Attribute("tileheight") );
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

    _tilesets.push_back( Tileset(
        imageNode->Attribute("source"),
        (unsigned int) atoi(tilesetNode->Attribute("tilewidth")),
        (unsigned int) atoi(tilesetNode->Attribute("tileheight")),
        (unsigned int) atoi(tilesetNode->Attribute("firstgid")),
        _resourceHolder
    ));

    return true;
}

bool TiledMap::processTileLayer(tinyxml2::XMLElement *tileLayerNode)
{
    // Поиск элемента с данными.
    tinyxml2::XMLElement *dataNode = tileLayerNode->FirstChildElement("data");
    if (!dataNode)
    {
        printf("[TiledMap::processTileLayer] Error: Can't find data node of layer: %s\n",
               tileLayerNode->Attribute("name"));
        return false;
    }

    // Определение наличия сжатия
    bool encoding = false;
    bool compression = false;

    if (strcmp(dataNode->Attribute("encoding"), "base64") == 0)
        encoding = true;

    if (strcmp(dataNode->Attribute("compression"), "zlib") == 0)
        compression = true;

    // Создание объекта со слоем.
    TileLayer layer(_resourceHolder);
    layer.setSize(
            (unsigned int) atoi(tileLayerNode->Attribute("width")),
            (unsigned int) atoi(tileLayerNode->Attribute("height"))
    );
    layer.setTileSize(
            _tileWidth,
            _tileHeight
    );
    layer.setTilesets( &_tilesets );

    if (!layer.setData(dataNode->GetText(), compression, encoding))
    {
        printf("[TiledMap::processTileLayer] Error: Can't proceed layer data of layer: %s\n",
               tileLayerNode->Attribute("name"));
        return false;
    }

    _tileLayers.push_back(layer);

    return true;
}

TiledMap::TileLayer::TileLayer(ResourceHolder *holder)
{
    _resourceHolder = holder;
}

TiledMap::TileLayer::~TileLayer()
{

}

void TiledMap::TileLayer::setResourceHolder(ResourceHolder *holder)
{
    _resourceHolder = holder;
}

ResourceHolder *TiledMap::TileLayer::resourceHolder() const
{
    return _resourceHolder;
}

void TiledMap::TileLayer::clear()
{
    _tileWidth = 0;
    _tileHeight = 0;

    _width = 0;
    _height = 0;

    _data.clear();
}

bool TiledMap::TileLayer::setData(std::string data, bool compression, bool encoding)
{
    if (!_tilesets)
    {
        printf("[TileLayer::setData] Error: Can't set data. No tileset set.\n");
        return false;
    }

    // Очистка данных.
    data.erase(std::remove(data.begin(), data.end(), ' '), data.end());
    data.erase(std::remove(data.begin(), data.end(), '\n'), data.end());

    const char * decodedData = nullptr;
    int length = 0;
    if (encoding)
        decodedData = Compression::base64Decode(data.c_str(), (int) data.length(), &length, false);
    else
    {
        length = (int) data.length();
        decodedData = data.c_str();
    }

    if (compression)
        decodedData = Compression::zlibInflate(decodedData, length, &length, encoding);

    if (_width * _height * 4 != length)
    {
        printf("[TileLayer::setData] Error: Data size is not equal with map size. %d * 4 != %d\n",
               _width * _height, length);
        return false;
    }

    // Распаковка карты
    _data.reserve( _width * _height );
    for (unsigned int tileIndex = 0; tileIndex < _width * _height; tileIndex++)
    {
        unsigned int byte = 0;
        for (unsigned int byteIndex = 0; byteIndex < 4; byteIndex++)
            byte += pow(256, byteIndex) * (unsigned char) decodedData[tileIndex * 4 + byteIndex];

        TileData tileData;
        tileData.id = byte;

        // Поиск правильного тайлсета
        unsigned int i=0;
        for (std::vector < TiledMap::Tileset >::iterator iterator = _tilesets->begin();
             iterator != _tilesets->end();
             iterator++, i++)
            if ((*iterator).containsId(byte))
                tileData.tilesetIndex = i;

        _data.push_back(tileData);
    }

    return true;
}

void TiledMap::TileLayer::setWidth(unsigned int width)
{
    _width = width;
}

unsigned int TiledMap::TileLayer::width() const
{
    return _width;
}

void TiledMap::TileLayer::setHeight(unsigned int height)
{
    _height = height;
}

unsigned int TiledMap::TileLayer::height() const
{
    return _height;
}

void TiledMap::TileLayer::setSize(unsigned int width, unsigned int height)
{
    _width = width;
    _height = height;
}

void TiledMap::TileLayer::setTileSize(unsigned int tileWidth, unsigned tileHeight)
{
    _tileWidth = tileWidth;
    _tileHeight = tileHeight;
}

void TiledMap::TileLayer::setTileWidth(unsigned int tileWidth)
{
    _tileWidth = tileWidth;
}

unsigned int TiledMap::TileLayer::tileWidth() const
{
    return _tileWidth;
}

void TiledMap::TileLayer::setTileHeight(unsigned int tileHeight)
{
    _tileHeight = tileHeight;
}

unsigned int TiledMap::TileLayer::tileHeight() const
{
    return _tileHeight;
}

bool TiledMap::renderLower(SDL_Renderer *renderer, unsigned int x, unsigned int y)
{
    for (unsigned int i=0; i < _tileLayers.size(); i++)
        _tileLayers[i].render( renderer, x, y );
}

void TiledMap::TileLayer::render(SDL_Renderer *renderer, unsigned int x, unsigned int y)
{
    for (unsigned int iy = 0; iy < _height; iy++)
        for (unsigned int ix = 0; ix < _width; ix++)
        {
            TileData data = _data[iy * _width + ix];
            Tileset tileset = _tilesets->operator[](data.tilesetIndex);
            SDL_Rect destignationRect = {
                    (int) (x + ix * _tileWidth),
                    (int) (y + iy * _tileHeight),
                    (int) _tileWidth,
                    (int) _tileHeight
            };
            SDL_Rect sourceRect = tileset.getTileSourceRect(data.id);
            if (SDL_RenderCopy(renderer, tileset.texture(), &sourceRect, &destignationRect))
            {
                printf("[TileLayer::render] Error: Can't render tile (ID: %d)\n"
                               "   Error: %s\n",
                       data.id, SDL_GetError());
                return;
            }
        }
}

void TiledMap::TileLayer::setTilesets(std::vector<TiledMap::Tileset> *tilesets)
{
    _tilesets = tilesets;
}

std::vector<TiledMap::Tileset> *TiledMap::TileLayer::tilesets() const
{
    return _tilesets;
}
