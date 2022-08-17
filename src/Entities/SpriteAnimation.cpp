#include "raylib.h"
#include "raymath.h"
#include "SpriteAnimation.h"
#include "GameObject.h"

void SpriteAnimation::Update(float dt)
{
    SpriteAnimation::Animation(dt);
}

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
    // DrawTextureEx(Sprite, Vector2Subtract(Position, Origin), Scale, Rotation, WHITE);
    Rectangle source{frame * width, 0, (Right ? 1 : -1) * width, Sprite.height};
    Rectangle dest{Position.x, Position.y, width, Sprite.height};
    DrawTexturePro(Sprite, source, dest, Origin, Rotation, SpriteColor);
}