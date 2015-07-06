#include <MainMenuScene.h>
#include <Colliders.h>
#include "Application.h"

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("[Main] SDL init error. Error: %s\n", SDL_GetError());
        return -1;
    }

    MainMenuScene scene;

    Application app;
    app.setMainScene(&scene);

    app.run();

    return 0;
}