//
// Created by megaxela on 04.07.15.
//

#ifndef GRAPHICS_SYSTEM_CAMERAFOLLOWCONTROLLER_H
#define GRAPHICS_SYSTEM_CAMERAFOLLOWCONTROLLER_H


#include "Entity.h"
#include "SettingsHolder.h"

class CameraFollowController
{
public:
    CameraFollowController( Camera *camera=nullptr );
    ~CameraFollowController();

    void setCamera( Camera *camera );
    Camera *camera() const;

    void setFollowTarget( Entity *entity );
    Entity* followTarget() const;

    void setSettings(SettingsHolder *settings);
    SettingsHolder *settings() const;

    void setMaxSpeed( float speed );
    float maxSpeed() const;

    void update();
private:
    float _maxSpeed;

    Entity *_followTarget;
    Camera *_camera;
    SettingsHolder *_settings;
};


#endif //GRAPHICS_SYSTEM_CAMERAFOLLOWCONTROLLER_H
