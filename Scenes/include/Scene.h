//
// Created by megaxela on 16.06.15.
//

#ifndef GRAPHICS_SYSTEM_SCENE_H
#define GRAPHICS_SYSTEM_SCENE_H

#include <SDL2/SDL.h>
#include "ResourceHolder.h"

class Scene
{
public:
    class MouseHolder
    {
    friend class Scene;

    public:
        MouseHolder();
        ~MouseHolder();

        int xDelta() const;
        int yDelta() const;

        int x() const;
        int y() const;

        bool isButtonPressed(int button);

    private:
        void updateState(int x, int y);
        void buttonPressed(int button);
        void buttonReleased(int button);

        std::vector < int > _pressedButtons;

        int _currentX;
        int _currentY;

        int _lastX;
        int _lastY;
    };

    Scene(SDL_Renderer *renderer=nullptr);
    virtual ~Scene();

    void loop();
    void stop();

    void setRenderer( SDL_Renderer *renderer);
    SDL_Renderer * renderer() const;

    void setResourceHolder( ResourceHolder *resourceHolder );
    ResourceHolder *resourceHolder() const;

protected:
    virtual void init();
    virtual void update();
    virtual void render();
    virtual void handleEvent( const SDL_Event &event );

    const MouseHolder &mouseHolder() const;

    SDL_Renderer *_renderer;
    ResourceHolder *_resourceHolder;
    float _fps;

private:
    void handleEvents();
    void handleSystemEvents( const SDL_Event &event );

    bool _loopDone;

    MouseHolder _mouseHolder;
};


#endif //GRAPHICS_SYSTEM_SCENE_H
