#ifndef COLLISION_CHARACTER_H
#define COLLISION_CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include <list>
#include "../TileMap.h"
#include "../Scene/Solid.h"

class CollisionCharacter
{

public:
    tiles *TilesData;
    int SolidTiles[19]{
        6, 7, 8,
        15, 16, 17,
        24, 25, 26,
        33, 34, 35,
        42, 43, 44,
        51, 52, 53, 45};
    Vector2 CollisionPos, CollisionOffset{0, 16};
    float CollisionRadius{8};

    bool CheckCollisionGrid(tiles tiles, float areaToCheck);
    bool CheckCollisionCharacter(Vector2 position, float radius)
    {
        return CheckCollisionCircles(GetCollisionPosition(), CollisionRadius, position, radius);
    }
    bool CheckTileIsSolid(int tile);

    bool CheckCollisionSolids(std::list<Solid *> solids);

    Vector2 GetCollisionPosition() { return Vector2Add(CollisionOffset, CollisionPos); }
};

#endif