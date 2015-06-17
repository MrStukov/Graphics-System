//
// Created by megaxela on 16.06.15.
//

#include "Application.h"

Application::Application(char const *title, int width, int height)
{
    _mainScene = nullptr;
    _ready = true;
    _window = SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_SHOWN);
    if (!_window)
    {
        printf("[Application::Application] Error: Can't init window. Error: %s\n", SDL_GetError());
        _ready = false;
        return;
    }

    // TODO: Разобраться с флагами
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!_renderer)
    {
        printf("[Application::Application] Error: Can't init renderer. Error: %s\n", SDL_GetError());
        _ready = false;
        return;
    }
}

Application::~Application()
{
    if (_window)
        SDL_DestroyWindow(_window);
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
}

void Application::setMainScene(Scene *scene)
{
    _mainScene = scene;
    if (_mainScene)
        _mainScene->setRenderer(_renderer);
}

Scene *Application::mainScene() const
{
    return _mainScene;
}

void Application::run()
{
    if (!_mainScene)
        printf("[Application::run] Error: Main scene was not set.\n");
    else
        _mainScene->loop();
}
