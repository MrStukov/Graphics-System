//
// Created by megaxela on 24.06.15.
//

#include "Camera.h"

Camera::Camera(int x, int y)
{
    _currentPosition.setX(x);
    _currentPosition.setY(y);

    _targetPosition = _currentPosition;
    _previousPosition = _currentPosition;

    _linearIterations = 0;
    _linearStep = 0.01f;

    _movingType = CameraMovingType_Linear;
}

Camera::Camera(const Vector2 &position)
{
    _currentPosition = position;
    _targetPosition = position;
    _previousPosition = position;

    _linearIterations = 0;
    _linearStep = 0.1f;

    _movingType = CameraMovingType_Linear;
}

Camera::~Camera()
{

}

int Camera::x() const
{
    return _currentPosition.intX();
}

int Camera::y() const
{
    return _currentPosition.intY();
}

Vector2 Camera::position() const
{
    return _currentPosition;
}

void Camera::setTargetPosition(const Vector2 &position)
{
    _previousPosition = _currentPosition;
    _targetPosition = position;
}

void Camera::update()
{
    switch (_movingType)
    {
    case CameraMovingType_Curve:
        _currentPosition.LerpTo(_targetPosition, 0.1f);
        break;
    case CameraMovingType_Linear:
        if (_linearIterations < 1)
        {
            _linearIterations += _linearStep;
            _currentPosition = Vector2::Lerp(
                    _previousPosition,
                    _targetPosition,
                    _linearIterations
            );
        }
        break;
    case CameraMovingType_Moment:
        _currentPosition = _targetPosition;
        break;
    }
}

Camera::CameraMovingType Camera::movingType() const
{
    return _movingType;
}

void Camera::setMovingType(Camera::CameraMovingType type)
{
    _movingType = type;
}
