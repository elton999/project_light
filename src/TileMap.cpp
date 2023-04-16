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

tiles ReadCollisionTiles()
{
    rapidcsv::Document doc("resources/maps/level1_collision.csv", rapidcsv::LabelParams(-1, -1));

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

bool IndexInTheList(int index, const int validTiles[], int len)
{
    for (int tile = 0; tile < len; tile++)
        if (index == validTiles[tile])
            return true;
    return false;
}

void DrawTile(int indexTile, Texture2D sprite, int posX, int posY)
{
    Vector2 sourcePos = GetGridPositionByIndex(indexTile, sprite.width / TILE_SIZE);
    sourcePos = Vector2Scale(sourcePos, TILE_SIZE);
    Rectangle source{sourcePos.y, sourcePos.x, TILE_SIZE, TILE_SIZE};

    Vector2 position = Vector2Scale({(float)posX, (float)posY}, TILE_SIZE);
    DrawTextureRec(sprite, source, position, WHITE);
}

void DrawTileMap(tiles tileData, Rectangle boundRender, Texture2D sprite, const int validTiles[], int len)
{
    Vector2 posGrid = GetGridPositionByScreenPosition({boundRender.x, boundRender.y});
    Vector2 sizeGrid = GetGridPositionByScreenPosition({boundRender.width, boundRender.height});

    for (int x = posGrid.x - 1; x < posGrid.x + sizeGrid.x + 1; x++)
        for (int y = posGrid.y - 1; y < posGrid.y + sizeGrid.y + 1; y++)
        {
            Vector2 indexPosition = Vector2Scale({x, y}, TILE_SIZE);
            Vector2 indexPositionBottom = Vector2Scale({x, y + 1}, TILE_SIZE);
            Vector2 indexPositionLast = Vector2Scale({x, posGrid.y + sizeGrid.y + 1}, TILE_SIZE);

            int indexTile = GetTileByPosition(indexPosition, tileData);
            int indexTileBottom = GetTileByPosition(indexPositionBottom, tileData);
            int indexTileLast = GetTileByPosition(indexPositionLast, tileData);

            if (IndexInTheList(indexTileLast + 1, validTiles, len) && IndexInTheList(indexTileBottom + 1, validTiles, len))
                if (indexTile != -1 && IndexInTheList(indexTile + 1, validTiles, len))
                {
                    DrawTile(indexTile, sprite, x, y);
                    // debug drawing
                    // DrawRectangleLines(indexPositionLast.x, indexPositionLast.y, TILE_SIZE, TILE_SIZE, WHITE);
                }
        }
}

void DrawTileMap(tiles tileData, Rectangle boundRender, Texture2D sprite)
{
    Vector2 posGrid = GetGridPositionByScreenPosition({boundRender.x, boundRender.y});
    Vector2 sizeGrid = GetGridPositionByScreenPosition({boundRender.width, boundRender.height});

    for (int x = posGrid.x - 1; x < posGrid.x + sizeGrid.x + 1; x++)
        for (int y = posGrid.y - 1; y < posGrid.y + sizeGrid.y + 1; y++)
        {
            int indexTile = GetTileByPosition(Vector2Scale({(float)x, (float)y}, TILE_SIZE), tileData);
            if (indexTile != -1)
                DrawTile(indexTile, sprite, x, y);
        }
}
