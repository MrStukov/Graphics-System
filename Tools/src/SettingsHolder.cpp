//
// Created by megaxela on 04.07.15.
//

#include "SettingsHolder.h"

SettingsHolder::SettingsHolder()
{
    _screenWidth = 800;
    _screenHeight = 600;
}

SettingsHolder::~SettingsHolder()
{

}

void SettingsHolder::setScreenSize(unsigned int width, unsigned int height)
{
    _screenWidth = width;
    _screenHeight = height;
}

unsigned int SettingsHolder::screenWidth() const
{
    return _screenWidth;
}

unsigned int SettingsHolder::screenHeight() const
{
    return _screenHeight;
}
