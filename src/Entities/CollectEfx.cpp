#include "CollectEfx.h"

void CollectEfx::Start()
{
    Sprite = LoadTexture("resources/efx/collect_efx.png");
    maxFrames = 20;
    frame = 0;
    Size = {30, 31};
    Origin = {0, 0};
    width = 30;
    height = 31;
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