#ifndef SOLID_H
#define SOLID_H

#include "raylib.h"
#include "raymath.h"

class Solid
{
public:
    Solid(Rectangle solidRec) { _solidRec = solidRec; }

    bool CheckCollision(Vector2 position, float radius)
    {
        return GetActive() && CheckCollisionCircleRec(position, radius, _solidRec);
    }
    bool GetActive() { return _isActive; }
    void SetActive(bool active) { _isActive = active; }

private:
    bool _isActive = true;
    Rectangle _solidRec;
};

#endif // SOLID_H