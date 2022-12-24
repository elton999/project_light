#include "Wall.h"

void Wall::Start()
{
    _sprite = LoadTexture("resources/tilemap/wall.png");
    Position = {888, 440};
}

void Wall::Update(float dt)
{
    if (_isVisible)
        return;

    _alpha = Clamp(_alpha - 5, 0, 255);
    _color.a = _alpha;
}

void Wall::Draw()
{
    DrawEffect();

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

void Wall::DrawEffect()
{
    if (_isVisible)
        return;

    DrawRectanglePro({Position.x, Position.y, 16, 96}, {0, 0}, 1.0f, _color);
}