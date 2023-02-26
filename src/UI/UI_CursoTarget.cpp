#include "UI_CursorTarget.h"
#include "raymath.h"

void UI_CursorTarget::Update(float dt)
{
    Origin = Vector2Divide({_dest.width, _dest.height}, {2.0f, 2.0f});
    _source = {Position.x, Position.y, _dest.width, _dest.height};
}

void UI_CursorTarget::Draw()
{
    DrawTexturePro(*_sprite, _dest, _source, {0, 0}, 1.0f, WHITE);
}