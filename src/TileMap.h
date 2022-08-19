#include <iostream>
#include <vector>
#include "Lib/rapidcsv.h"
#include "raylib.h"
#include "raymath.h"
#include <sstream>

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

Vector2 GetInGrid(int num, int width, int height)
{
    return Vector2{
        (float)num / (float)width,
        (float)fmod(num, height),
    };
}

void DrawTileMap(tiles tileData, Texture2D sprite)
{
    for (int i = 0; i < tileData.data.size(); i++)
    {
        if (tileData.data[i] != -1)
        {
            Vector2 sourcePos = GetInGrid(tileData.data[i], 7, 7);
            sourcePos = Vector2Scale(sourcePos, 8);
            Rectangle source{sourcePos.y, sourcePos.x, 8, 8};
            Vector2 offset{50, 50};

            Vector2 position = GetInGrid(i, tileData.width, tileData.height);

            position = Vector2Scale(position, 8);
            position = Vector2Add(position, offset);

            DrawTextureRec(sprite, source, position, WHITE);
        }
    }
}
