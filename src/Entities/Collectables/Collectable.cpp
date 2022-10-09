#include "Collectable.h"
#include "raymath.h"
#include "../../Colors.h"

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

    // Shadow animation
    float radioShadow = (floatingFactor + floatingDistance) / 2 + shadowMiniSize;
    DrawCircle(Position.x + Source.width / 2, Position.y + Source.y, radioShadow, SHADOW);

    // Sprite render
    Rectangle dest{Position.x, Position.y + floatingFactor, Size.x, Size.y};
    DrawTexturePro(*Sprite, Source, dest, Origin, 1.0f, WHITE);
}