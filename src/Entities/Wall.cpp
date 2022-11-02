#include "Wall.h"

void Wall::Start()
{
    _sprite = LoadTexture("resources/tilemap/wall.png");
    Position = {888, 440};
}

void Wall::Update(float dt)
{
}

void Wall::Draw()
{
    for (int i = 0; i < _numOfBlocks; i++)
    {
        Vector2 position = {Position.x, Position.y + i * _offsetBlock};

        Rectangle source = {0,
                            i == _numOfBlocks / 2 ? 0 : 24,
                            16,
                            i == _numOfBlocks - 1 ? 16 : 24};
        Rectangle dest = {position.x, position.y, 16, i == _numOfBlocks - 1 ? 16 : 24};

        DrawTexturePro(_sprite, source, dest, {0, 0}, 1.0f, WHITE);
    }
}