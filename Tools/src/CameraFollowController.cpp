//
// Created by megaxela on 04.07.15.
//

#include "CameraFollowController.h"

CameraFollowController::CameraFollowController(Camera *camera)
{
    _camera = camera;
    _settings = nullptr;
    _followTarget = nullptr;
    _maxSpeed = 10;
}

CameraFollowController::~CameraFollowController()
{

}

void CameraFollowController::setCamera(Camera *camera)
{
    _camera = camera;
}

Camera *CameraFollowController::camera() const
{
    return _camera;
}

void CameraFollowController::setFollowTarget(Entity *entity)
{
    _followTarget = entity;
}

Entity *CameraFollowController::followTarget() const
{
    return _followTarget;
}

void CameraFollowController::setSettings(SettingsHolder *settings)
{
    _settings = settings;
}

SettingsHolder *CameraFollowController::settings() const
{
    return _settings;
}

void CameraFollowController::update()
{
    if (!_followTarget)
        return;

    if (!_camera)
        return;

    if (!_settings)
        return;

    // TODO: Изменть реализацию. (Хотя пока и так норм)
    Vector2 targetPosition = _followTarget->position();
    // Корректирование позиции от размера экрана и размера цели
    targetPosition -= Vector2(
            (float) ((int) _settings->screenWidth() / (int) 2) - ((int)  _followTarget->width() / (int) 2),
            (float) ((int) _settings->screenHeight() / (int) 2) - ((int) _followTarget->height() / (int) 2)
    );

    _camera->setTargetPosition( targetPosition );
}

void CameraFollowController::setMaxSpeed(float speed)
{
    _maxSpeed = speed;
}

float CameraFollowController::maxSpeed() const
{
    return _maxSpeed;
}
