#ifndef SOLID_H
#define SOLID_H

#include "raylib.h"
#include "raymath.h"
class Scene;

class Solid
{
private:
    bool _active{true};
    Rectangle _solidRec;
    Scene *_scene;

public:
    Solid(Rectangle solidRec) { _solidRec = solidRec; }

    void SetTriggerArea(Rectangle solidRec) { _solidRec = solidRec; }

    bool CheckCollision(Vector2 position, float radius)
    {
        return GetActive() && CheckCollisionCircleRec(position, radius, _solidRec);
    }
    bool GetActive() { return _active; }
    void SetActive(bool active) { _active = active; }
};

#endif // SOLID_H