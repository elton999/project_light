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

const int wallTiles[18]{
    7, 8, 9,
    16, 17, 18,
    25, 26, 27,
    34, 35, 36,
    43, 44, 45,
    52, 53, 54};

const int backgroundTiles[36]{
    1, 2, 3, 4, 5, 6,
    10, 11, 12, 13, 14, 15,
    19, 20, 21, 22, 23, 24,
    28, 29, 30, 31, 32, 33,
    37, 38, 39, 40, 41, 42,
    46, 47, 48, 49, 50, 51};

tiles ReadTileMap();

Vector2 GetGridPositionByIndex(int num, int width);

Vector2 GetGridPositionByScreenPosition(Vector2 position);

int GetTileByPosition(Vector2 position, tiles tileData);

bool IndexInTheList(int index, const int *validTiles, int len);

void DrawTileMap(tiles tileData, Rectangle boundRender, Texture2D sprite, const int *validTiles, int len);

#endif