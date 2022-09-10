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
        return CheckCollisionCircleRec(character.CollisionPos, character.CollisionRadius, _solidRec);
    }

private:
    Rectangle _solidRec;
};

#endif // SOLID_H