//
// Created by megaxela on 04.07.15.
//

#ifndef GRAPHICS_SYSTEM_SETTINGSHOLDER_H
#define GRAPHICS_SYSTEM_SETTINGSHOLDER_H

class SettingsHolder
{
public:
    SettingsHolder();
    ~SettingsHolder();

    void setScreenSize( unsigned int width, unsigned int height );
    unsigned int screenWidth() const;
    unsigned int screenHeight() const;

private:
    // Размер экрана
    unsigned int _screenWidth;
    unsigned int _screenHeight;
};


#endif //GRAPHICS_SYSTEM_SETTINGSHOLDER_H
