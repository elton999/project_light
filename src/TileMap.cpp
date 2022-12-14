#include "Lib/rapidcsv.h"
#include <iostream>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include <sstream>
#include "TileMap.h"

tiles ReadTileMap()
{
    rapidcsv::Document doc("resources/maps/level1.csv", rapidcsv::LabelParams(-1, -1));

    tiles dataTiles;

    dataTiles.height = doc.GetRowCount();
    dataTiles.width = doc.GetColumnCount();

    for (int x = 0; x < dataTiles.width; x++)
        for (int y = 0; y < dataTiles.height; y++)
            dataTiles.data.insert(dataTiles.data.end(), doc.GetCell<int>(x, y));

    return dataTiles;
}

Vector2 GetGridPositionByIndex(int num, int width)
{
    return Vector2{
        std::truncf((float)num / (float)width),
        std::truncf((float)fmod(num, (float)width)),
    };
}

Vector2 GetGridPositionByScreenPosition(Vector2 position)
{
    int x = std::roundf(position.x / TILE_SIZE);
    int y = std::roundf(position.y / TILE_SIZE);
    return Vector2{(float)x, (float)y};
}

int GetTileByPosition(Vector2 position, tiles tileData)
{
    Vector2 pos = GetGridPositionByScreenPosition(position);

    if (pos.x >= 0 && pos.y >= 0 && pos.x < tileData.width && pos.y < tileData.height)
    {
        int tile = (tileData.width) * pos.x + pos.y;
        return tileData.data[tile];
    }

    return -1;
}

void DrawTileMap(tiles tileData, Rectangle boundRender, Texture2D sprite)
{
    Vector2 posGrid = GetGridPositionByScreenPosition({boundRender.x - boundRender.width / 2.f, boundRender.y - boundRender.height / 2.f});
    Vector2 sizeGrid = GetGridPositionByScreenPosition({boundRender.width, boundRender.height});

    for (int x = posGrid.x - 1; x < posGrid.x + sizeGrid.x + 1; x++)
    {
        for (int y = posGrid.y - 1; y < posGrid.y + sizeGrid.y + 1; y++)
        {
            int indexTile = GetTileByPosition(Vector2Scale({(float)x, (float)y}, TILE_SIZE), tileData);
            if (indexTile != -1)
            {
                Vector2 sourcePos = GetGridPositionByIndex(indexTile, sprite.width / TILE_SIZE);
                sourcePos = Vector2Scale(sourcePos, TILE_SIZE);
                Rectangle source{sourcePos.y, sourcePos.x, TILE_SIZE, TILE_SIZE};

                Vector2 position = Vector2Scale({(float)x, (float)y}, TILE_SIZE);
                DrawTextureRec(sprite, source, position, WHITE);
            }
        }
    }
}