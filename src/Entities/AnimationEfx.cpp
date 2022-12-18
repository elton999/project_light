#include "raylib.h"
#include "AnimationEfx.h"

void AnimationEfx::Start()
{
    Sprite = LoadTexture("resources/efx/collision_efx.png");
    maxFrames = 3;
    frame = 2;
    Size = {16, 16};
    Origin = {8, 8};
    width = 16;
    height = 16;
}

void AnimationEfx::Update(float dt)
{
    if (IsAnimationFinished())
        return;

    Animation(dt);
}

void AnimationEfx::Draw()
{
    SpriteAnimation::Draw();
}

void AnimationEfx::StartAnimation()
{
    frame = 0;
    runningTime = 0;
}

bool AnimationEfx::IsAnimationFinished()
{
    return frame >= maxFrames - 1;
}