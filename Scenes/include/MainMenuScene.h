//
// Created by megaxela on 17.06.15.
//

#ifndef GRAPHICS_SYSTEM_MAINMENUSCENE_H
#define GRAPHICS_SYSTEM_MAINMENUSCENE_H

#include <Scene.h>
#include <vector>

class MainMenuScene : public Scene
{
public:
    MainMenuScene();

protected:
    void render() override;
    void update() override;
    void handleEvents() override;

private:

};


#endif //GRAPHICS_SYSTEM_MAINMENUSCENE_H
