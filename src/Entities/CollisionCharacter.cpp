#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "CollisionCharacter.h"

bool CollisionCharacter::CheckCollisionGrid(tiles tiles, float areaToCheck)
{
    Vector2 pos = GetGridPositionByScreenPosition({CollisionPos.x - 16, CollisionPos.y - 16});
    for (int y = pos.y - areaToCheck; y < pos.y + areaToCheck; y++)
    {
        for (int x = pos.x - areaToCheck; x < pos.x + areaToCheck; x++)
        {
            Vector2 posScaled = Vector2Scale({x, y}, TILE_SIZE);
            Rectangle tileRec = {posScaled.x, posScaled.y, TILE_SIZE, TILE_SIZE};
            int tileIndex = GetTileByPosition(posScaled, tiles);

            if (CheckCollisionCircleRec(GetCollisionPosition(), CollisionRadius, tileRec) && CheckTileIsSolid(tileIndex))
                return true;
        }
    }

    return false;
}

bool CollisionCharacter::CheckTileIsSolid(int tile)
{
    for (auto solidTile : SolidTiles)
        if (tile == solidTile)
            return true;

    return false;
}