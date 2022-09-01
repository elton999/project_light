#include "raylib.h"
#include "CollisionCharacter.h"

bool CollisionCharacter::CheckCollisionGrid(tiles tiles, float areaToCheck)
{
    Vector2 pos = GetGridPositionByScreenPosition(GetCollisionPosition(), tiles);
    Vector2 posMin = Vector2Scale(pos, -areaToCheck);
    Vector2 posMax = Vector2Scale(pos, areaToCheck);

    for (int x = posMin.x; x < posMax.x; x++)
    {
        for (int y = posMin.y; y < posMax.y; y++)
        {
            Vector2 posScaled = Vector2Scale({x, y}, TILE_SIZE);
            Rectangle tileRec = {posScaled.x, posScaled.y, TILE_SIZE, TILE_SIZE};

            if (CheckCollisionCircleRec(GetCollisionPosition(), CollisionRadius, tileRec))
            {
                int tileIndex = GetTileByPosition(posScaled, tiles);
                if (CheckTileIsSolid(tileIndex))
                    return true;
            }
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