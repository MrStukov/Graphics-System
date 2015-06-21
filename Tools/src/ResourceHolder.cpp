//
// Created by megaxela on 18.06.15.
//

#include "ResourceHolder.h"

ResourceHolder::ResourceHolder(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

ResourceHolder::~ResourceHolder()
{
    clear();
}

SDL_Texture *ResourceHolder::loadTexture(const std::string &path)
{
    // TODO: Сменить printf на logger
    if (!_renderer)
    {
        printf("[ResourceHolder::loadTexture] Error: renderer required for loading.\n");
        return nullptr;
    }

    // Поиск ключа в ассоциативном массиве _textures.
    for (std::map< std::string, SDL_Texture* >::iterator iterator = _textures.begin();
         iterator != _textures.end();
         iterator++)
        if (path == iterator->first)
            return iterator->second;

    // Загрузка
    SDL_Texture *texture = IMG_LoadTexture(_renderer, path.c_str());
    if (!texture)
    {
        printf("[ResourceHolder::loadtexture] Error: Can't load image: %s.\n   Error: %s\n",
               path.c_str(), SDL_GetError());
        return nullptr;
    }

    printf("[ResourceHolder::loadTexture] Info: Image loaded: %s\n",
           path.c_str());
    _textures[path] = texture;
    return texture;
}

void ResourceHolder::setRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

SDL_Renderer *ResourceHolder::renderer() const
{
    return _renderer;
}

void ResourceHolder::clear()
{
    for (std::map < std::string, SDL_Texture* >::iterator iterator = _textures.begin();
         iterator != _textures.end();
         iterator++)
        SDL_DestroyTexture(iterator->second);
    _textures.clear();
}
