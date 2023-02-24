#include "UI_CutSceneBars.h"
#include "raymath.h"

void UI_CutSceneBars::Update(float dt)
{
    float speed = _speed;
    if (_show)
        speed = -_speed;

    _positionBar1 = {_positionBar1.x, Clamp(_positionBar1.y - speed * dt, -_size.y, 0)};
    _positionBar2 = {_positionBar2.x, Clamp(_positionBar2.y + speed * dt, 240.0f - _size.y, 240.0f)};
}

void UI_CutSceneBars::Draw()
{
    DrawRectangle((int)_positionBar1.x, (int)_positionBar1.y, (int)_size.x, (int)_size.y, BLACK);
    DrawRectangle((int)_positionBar2.x, (int)_positionBar2.y, (int)_size.x, (int)_size.y, BLACK);
}