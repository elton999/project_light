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
    if (!_isVisible)
        return;

    for (int i = 0; i < _numOfBlocks; i++)
    {
        Vector2 position = {Position.x, Position.y + i * _offsetBlock};

        Rectangle source = {0.0f,
                            i == _numOfBlocks / 2 ? 0.0f : 24.0f,
                            16.0f,
                            i == _numOfBlocks - 1 ? 16.0f : 24.0f};
        Rectangle dest = {position.x, position.y, 16.0f, i == _numOfBlocks - 1 ? 16.0f : 24.0f};

        DrawTexturePro(_sprite, source, dest, {0, 0}, 1.0f, WHITE);
    }
}