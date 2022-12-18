#include "CollectEfx.h"

void CollectEfx::Start()
{
    Sprite = LoadTexture("resources/efx/collect_efx.png");
    maxFrames = 25;
    frame = 0;
    Size = {64, 64};
    Origin = {16, 16};
    width = 64;
    height = 64;
}

void CollectEfx::Update(float dt)
{
    AnimationTime -= dt;
    if (AnimationTime <= 0.0f)
        return;
    AnimationEfx::Update(dt);
}

void CollectEfx::Draw()
{
    if (AnimationTime <= 0.0f)
        return;
    AnimationEfx::Draw();
}