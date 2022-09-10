#ifndef SOLID_H
#define SOLID_H

#include "raylib.h"
#include "raymath.h"
#include "../Entities/CollisionCharacter.h"

class Solid
{
public:
    Solid(Rectangle solidRec) { _solidRec = solidRec; }

    bool CheckCollision(CollisionCharacter character)
    {
        return GetActive() && CheckCollisionCircleRec(character.CollisionPos, character.CollisionRadius, _solidRec);
    }
    bool GetActive() { return _isActive; }
    void SetActive(bool active) { _isActive = active; }

private:
    bool _isActive = true;
    Rectangle _solidRec;
};

#endif // SOLID_H