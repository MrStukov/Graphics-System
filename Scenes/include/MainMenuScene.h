//
// Created by megaxela on 17.06.15.
//

#ifndef GRAPHICS_SYSTEM_MAINMENUSCENE_H
#define GRAPHICS_SYSTEM_MAINMENUSCENE_H

#include <Scene.h>
#include <vector>
#include <ScreenButton.h>
#include <algorithm>
#include <functional>

class MainMenuScene : public Scene
{
public:
    MainMenuScene();

protected:
    void render() override;
    void update() override;
    void handleEvent( const SDL_Event &event ) override;

    virtual void init() override;

private:
    void functionExit();
    void functionLoadTestMap();

    std::vector < ScreenButton > _buttons;
};


#endif //GRAPHICS_SYSTEM_MAINMENUSCENE_H
