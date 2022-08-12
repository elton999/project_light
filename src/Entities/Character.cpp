#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "GameObject.h"

void Character::Animation(float dt)
{
}

void Character::Draw()
{
    DrawTextureEx(Sprite, Vector2Subtract(Position, Origin), Scale, Rotation, WHITE);
}