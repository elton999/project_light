#ifndef ICAMERA_TARGET
#define ICAMERA_TARGET

#include "raylib.h"

class ICameraTarget
{
public:
    virtual Vector2 GetTargetPosition();
};

#endif // ICAMERA_TARGET