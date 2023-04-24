#include "Sarah.h"

void Sarah::Start()
{
    _sprite = LoadTexture("resources/sarah_idle.png");
    Position = {915, 205};
    SetTriggerArea({Position.x, Position.y, _sprite.width, _sprite.height});
}

void Sarah::Update(float dt) {}

void Sarah::Draw()
{
    DrawTexture(_sprite, Position.x, Position.y, WHITE);
}