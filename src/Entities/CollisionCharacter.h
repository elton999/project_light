#ifndef COLLISION_CHARACTER_H
#define COLLISION_CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include "../TileMap.h"

class CollisionCharacter
{

public:
    int SolidTiles[1];
    Vector2 Position, Offset;
    float Radius{16};

    bool CheckCollisionGrid(tiles tiles);
    bool CheckCollisionCharacter(Vector2 position, float radius)
    {
        return CheckCollisionCircles(Vector2Add(Position, Offset), Radius, position, radius);
    }
};

#endif