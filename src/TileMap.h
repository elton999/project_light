#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "Lib/rapidcsv.h"
#include <iostream>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include <sstream>

#define TILE_SIZE 8.0f

struct tiles
{
    std::vector<int> data;
    int height;
    int width;
};

tiles ReadTileMap();

Vector2 GetGridPositionByIndex(int num, int width);

Vector2 GetGridPositionByScreenPosition(Vector2 position);

int GetTileByPosition(Vector2 position, tiles tileData);

void DrawTileMap(tiles tileData, Rectangle boundRender, Texture2D sprite);

#endif