//
// Created by megaxela on 16.06.15.
//

#ifndef GRAPHICS_SYSTEM_APPLICATION_H
#define GRAPHICS_SYSTEM_APPLICATION_H

#include "Scene.h"

class Application
{
public:
    Application(char const* title="TEST", int width=800, int height=600);
    ~Application();

    void setMainScene(Scene *scene);
    Scene* mainScene() const;

    void run();
private:
    Scene *_mainScene;

    SDL_Window *_window;
    SDL_Renderer *_renderer;
    bool _ready;
};


#endif //GRAPHICS_SYSTEM_APPLICATION_H
