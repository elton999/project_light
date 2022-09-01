#ifndef COLLISION_CHARACTER_H
#define COLLISION_CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include "../TileMap.h"

class CollisionCharacter
{

public:
    int SolidTiles[18]{7, 8, 9, 16, 17, 18, 25, 26, 27, 34, 35, 36, 43, 44, 45, 52, 53, 54};
    Vector2 CollisionPos, CollisionOffset{8, 8};
    float CollisionRadius{8};

    bool CheckCollisionGrid(tiles tiles, float areaToCheck);
    bool CheckCollisionCharacter(Vector2 position, float radius)
    {
        return CheckCollisionCircles(GetCollisionPosition(), CollisionRadius, position, radius);
    }
    bool CheckTileIsSolid(int tile);

    Vector2 GetCollisionPosition() { return Vector2Add(CollisionOffset, CollisionPos); }
};

#endif