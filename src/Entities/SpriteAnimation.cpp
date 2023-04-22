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
    bool isLastFrame = frame > maxFrames;

    if (isLastFrame && AnimationDirection == LOOP)
        frame = 0;

    if (isLastFrame && AnimationDirection == FORWARD)
        frame--;
}

void SpriteAnimation::Draw()
{
    Rectangle source{frame * Size.x, 0, (Right ? 1 : -1) * Size.x, Size.y};
    Rectangle dest{Position.x, Position.y, (float)width, (float)height};
    DrawTexturePro(Sprite, source, dest, Origin, Rotation, SpriteColor);
}