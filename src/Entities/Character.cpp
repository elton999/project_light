#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "GameObject.h"

void Character::Update(float dt)
{
    Character::Animation(dt);
}

void Character::Animation(float dt)
{
    runningTime += dt;
    if (runningTime < updateTime)
        return;

    frame++;
    runningTime = 0.f;
    if (frame > maxFrames)
        frame = 0;
}

void Character::Draw()
{
    // DrawTextureEx(Sprite, Vector2Subtract(Position, Origin), Scale, Rotation, WHITE);
    Rectangle source{frame * 32, 0, (Right ? 1 : -1) * 32, 32};
    Rectangle dest{Position.x, Position.y, 32, 32};
    DrawTexturePro(Sprite, source, dest, Origin, Rotation, SpriteColor);
}