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

const int wallTiles[19]{6, 7, 8, 15, 16, 17, 24, 25, 26, 33, 34, 35, 42, 43, 44, 51, 52, 53, 45};
const int backgroundTiles[11]{};

tiles ReadTileMap();

Vector2 GetGridPositionByIndex(int num, int width);

Vector2 GetGridPositionByScreenPosition(Vector2 position);

int GetTileByPosition(Vector2 position, tiles tileData);

bool IndexInTheList(int index, const int *validTiles, int len);

void DrawTileMap(tiles tileData, Rectangle boundRender, Texture2D sprite, const int *validTiles, int len);

#endif