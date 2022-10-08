#include "Collectable.h"
#include "raymath.h"

void Collectable::Update(float dt)
{
    if (!GetActive())
        return;
    timerElapsed += dt;
    floatingFactor = cosf(timerElapsed * floatingSpeed) * floatingDistance;
}

void Collectable::Draw()
{
    if (!GetActive())
        return;
    Rectangle dest{Position.x, Position.y + floatingFactor, Size.x, Size.y};
    DrawTexturePro(*Sprite, Source, dest, Origin, 1.0f, WHITE);
}