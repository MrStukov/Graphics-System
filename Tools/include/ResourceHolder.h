//
// Created by megaxela on 18.06.15.
//

#ifndef GRAPHICS_SYSTEM_RESOURCEHOLDER_H
#define GRAPHICS_SYSTEM_RESOURCEHOLDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>
#include <algorithm>

class ResourceHolder
{
public:
    ResourceHolder(SDL_Renderer *renderer=nullptr);
    ~ResourceHolder();

    SDL_Texture* loadTexture(const std::string &path);

    void setRenderer( SDL_Renderer *renderer);
    SDL_Renderer* renderer() const;

    void clear();
private:
    SDL_Renderer *_renderer;

    std::map<std::string, SDL_Texture*> _textures;
};


#endif //GRAPHICS_SYSTEM_RESOURCEHOLDER_H
