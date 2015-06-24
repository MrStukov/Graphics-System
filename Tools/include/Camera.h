//
// Created by megaxela on 24.06.15.
//

#ifndef GRAPHICS_SYSTEM_CAMERA_H
#define GRAPHICS_SYSTEM_CAMERA_H

#include "Vector2.h"

class Camera
{
public:
    enum CameraMovingType
    {
        CameraMovingType_Linear,
        CameraMovingType_Curve,
        CameraMovingType_Moment
    };

    Camera(int x=0, int y=0);
    Camera(const Vector2 &position );
    ~Camera();

    int x() const;
    int y() const;

    Vector2 position() const;

    void setTargetPosition( const Vector2 &position );

    CameraMovingType movingType() const;

    void setMovingType( CameraMovingType type );

    void udpate( float deltaTime );
private:
    CameraMovingType _movingType;

    Vector2 _previousPosition;

    float _linearIterations;
    float _linearStep;
    Vector2 _currentPosition;

    Vector2 _targetPosition;
};


#endif //GRAPHICS_SYSTEM_CAMERA_H
