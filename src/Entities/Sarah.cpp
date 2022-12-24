#include "Sarah.h"

void Sarah::Start()
{
    _sprite = LoadTexture("resources/sarah_idle.png");
    Position = {915, 205};
}

void Sarah::Update(float dt) {}

void Sarah::Draw()
{
    DrawTexture(_sprite, Position.x, Position.y, WHITE);
}