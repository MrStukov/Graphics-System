//

#include "Scene.h"

Scene::Scene(SDL_Renderer *renderer)
{
    _renderer = renderer;
    _loopDone = false;
}

//
// Created by megaxela on 16.06.15.
Scene::Scene(Scene *parent)
{
    _renderer = parent->_renderer;
    _resourceHolder = parent->_resourceHolder;
}

Scene::~Scene()
{

}

void Scene::loop()
{
    init();
    _loopDone = false;
    unsigned int ticks = 0;
    unsigned int resultTicks = SDL_GetTicks();
    unsigned int difference = 0;
    _fps = 60;
    unsigned int expectedTicks = 1000 / 60;
    while (!_loopDone)
    {
        handleEvents();
        update();
        render();

        // Ожидание разницы в кадрах
        ticks = resultTicks;
        resultTicks = SDL_GetTicks();
        difference = resultTicks - ticks;

        _fps = (_fps + 1000.0f / difference) / 2;
//        printf("FPS: %f\n", _fps);
        if (expectedTicks > resultTicks)
            SDL_Delay( expectedTicks - difference );
    }
}

void Scene::update()
{

}

void Scene::render()
{

}

void Scene::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // Перегружаемая
        handleEvent(event);

        // Не перегружаемая
        handleSystemEvents(event);
    }
}

void Scene::setRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

SDL_Renderer * Scene::renderer() const
{
    return _renderer;
}

void Scene::stop()
{
    _loopDone = true;
}

void Scene::setResourceHolder(ResourceHolder *resourceHolder)
{
    _resourceHolder = resourceHolder;
}

ResourceHolder *Scene::resourceHolder() const
{
    return _resourceHolder;
}

void Scene::init()
{

}

Scene::MouseHolder const &Scene::mouseHolder() const
{
    return _mouseHolder;
}

Scene::KeyboardHolder const &Scene::keyboardHolder() const
{
    return _keyboardHolder;
}

void Scene::handleEvent(const SDL_Event &event)
{

}

void Scene::handleSystemEvents(const SDL_Event &event)
{
    // TODO: Добавить обработку клавиатуры и мыши
    switch (event.type)
    {
    case SDL_QUIT:
        exit(0);
        break;

    case SDL_MOUSEMOTION:
        _mouseHolder.updateState(event.motion.x, event.motion.y);
        break;

    case SDL_MOUSEBUTTONDOWN:
        _mouseHolder.buttonPressed(event.button.button);
        break;

    case SDL_MOUSEBUTTONUP:
        _mouseHolder.buttonReleased(event.button.button);
        break;

    case SDL_KEYDOWN:
        _keyboardHolder.keyPressed( event.key.keysym.sym );
        break;

    case SDL_KEYUP:
        _keyboardHolder.keyReleased( event.key.keysym.sym );
        break;

    default:
        break;
    }
}

// MOUSE
Scene::MouseHolder::MouseHolder()
{
    _currentX = 0;
    _currentY = 0;
}

Scene::MouseHolder::~MouseHolder()
{

}

void Scene::MouseHolder::updateState(int x, int y)
{
    _lastX = _currentX;
    _lastY = _currentY;

    _currentX = x;
    _currentY = y;
}

int Scene::MouseHolder::xDelta() const
{
    return _lastX - _currentX;
}

int Scene::MouseHolder::yDelta() const
{
    return _lastY - _currentY;
}

int Scene::MouseHolder::x() const
{
    return _currentX;
}

int Scene::MouseHolder::y() const
{
    return _currentY;
}

void Scene::MouseHolder::buttonPressed(int button)
{
    std::vector<int>::iterator pos = std::find(
            _pressedButtons.begin(),
            _pressedButtons.end(),
            button
    );

    if (pos == _pressedButtons.end())
        _pressedButtons.push_back(button);
}

void Scene::MouseHolder::buttonReleased(int button)
{
    std::vector<int>::iterator pos = std::find(
            _pressedButtons.begin(),
            _pressedButtons.end(),
            button
    );

    if (pos != _pressedButtons.end())
        _pressedButtons.erase(pos);
}

bool Scene::MouseHolder::isButtonPressed(int button) const
{
    return std::find(
            _pressedButtons.begin(),
            _pressedButtons.end(),
            button
    ) != _pressedButtons.end();
}

// KEYBOARD
Scene::KeyboardHolder::KeyboardHolder()
{

}

Scene::KeyboardHolder::~KeyboardHolder()
{

}

bool Scene::KeyboardHolder::isKeyPressed(int key) const
{
    return std::find(
            _pressedKeys.begin(),
            _pressedKeys.end(),
            key
    ) != _pressedKeys.end();
}

void Scene::KeyboardHolder::keyPressed(int key)
{
    std::vector<int>::iterator pos = std::find(
            _pressedKeys.begin(),
            _pressedKeys.end(),
            key
    );

    if (pos != _pressedKeys.end())
        _pressedKeys.push_back(key);
}

void Scene::KeyboardHolder::keyReleased(int key)
{
    std::vector<int>::iterator pos = std::find(
            _pressedKeys.begin(),
            _pressedKeys.end(),
            key
    );

    if (pos != _pressedKeys.end())
        _pressedKeys.erase(pos);
}
