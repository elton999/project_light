#include "CollectEfx.h"

void CollectEfx::Start()
{
    Sprite = LoadTexture("resources/efx/collect_efx.png");
    maxFrames = 8;
    frame = 0;
    Size = {24, 18};
    Origin = {0, 0};
    width = 24;
    height = 18;
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