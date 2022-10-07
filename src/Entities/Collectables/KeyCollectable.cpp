#include "KeyCollectable.h"
#include "raymath.h"

void KeyCollectable::Start()
{
    Size = {16, 16};
    Source = {0, Size.y, Size.x, Size.y};
    Position = {100, 100};
}

void KeyCollectable::Update(float dt)
{
    timerElapsed += dt;
    floatingFactor = cosf(timerElapsed * floatingSpeed) * floatingDistance;
}

void KeyCollectable::Draw()
{
    Rectangle dest{Position.x, Position.y + floatingFactor, Size.x, Size.y};

    DrawTexturePro(*Sprite, Source, dest, Origin, 1.0f, WHITE);
}