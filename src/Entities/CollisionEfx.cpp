#include "raylib.h"
#include "CollisionEfx.h"

void CollisionEfx::Start()
{
    Sprite = LoadTexture("resources/efx/collision_efx.png");
    maxFrames = 3;
    frame = 2;
    Size = {16, 16};
    Origin = {8, 8};
    width = 16;
    height = 16;
}

void CollisionEfx::StartAnimation()
{
    frame = 0;
    runningTime = 0;
}

bool CollisionEfx::IsAnimationFinished()
{
    return frame >= maxFrames - 1;
}