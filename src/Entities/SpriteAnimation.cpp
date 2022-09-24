#include "raylib.h"
#include "raymath.h"
#include "SpriteAnimation.h"

void SpriteAnimation::Animation(float dt)
{
    runningTime += dt;
    if (runningTime < updateTime)
        return;

    frame++;
    runningTime = 0.f;
    if (frame > maxFrames)
        frame = 0;
}

void SpriteAnimation::Draw()
{
    Rectangle source{frame * Size.x, 0, (Right ? 1 : -1) * Size.x, Size.y};
    Rectangle dest{Position.x, Position.y, width, height};
    DrawTexturePro(Sprite, source, dest, Origin, Rotation, SpriteColor);
}