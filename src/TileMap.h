#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <iostream>
#include <vector>
#include "Lib/rapidcsv.h"
#include "raylib.h"
#include "raymath.h"
#include <sstream>

#define TILE_SIZE 8

struct tiles
{
    std::vector<int> data;
    int height;
    int width;
};

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

Vector2 GetGridPositionByScreenPosition(Vector2 position, tiles tileData)
{
    int x = std::truncf(position.x / TILE_SIZE);
    int y = std::truncf(position.y / TILE_SIZE);
    return Vector2{(float)x, (float)y};
}

int GetTileByPosition(Vector2 position, tiles tileData)
{
    Vector2 pos = GetGridPositionByScreenPosition(position, tileData);

    if (!(pos.x < 0 || pos.y < 0 || pos.x >= tileData.width || pos.y >= tileData.height))
    {
        int tile = tileData.width * pos.y + pos.x;
        return tileData.data[tile];
    }

    return -1;
}

void DrawTileMap(tiles tileData, Texture2D sprite)
{
    for (int i = 0; i < tileData.data.size(); i++)
    {
        if (tileData.data[i] != -1)
        {
            Vector2 sourcePos = GetGridPositionByIndex(tileData.data[i], tileData.width);
            sourcePos = Vector2Scale(sourcePos, TILE_SIZE);
            Rectangle source{sourcePos.y, sourcePos.x, TILE_SIZE, TILE_SIZE};

            Vector2 position = GetGridPositionByIndex(i, tileData.width);
            position = Vector2Scale(position, TILE_SIZE);

            DrawTextureRec(sprite, source, position, WHITE);
        }
    }
}

#endif