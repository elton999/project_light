#include "raylib.h"
#include "raymath.h"
#include "Bullet.h"
#include "GameObject.h"

void Bullet::Start()
{
    Size = {10, 10};
    Origin = {5, 5};
    Speed = 180.0f;
    Position = {0, 0};
    ColorSquare = RED;
}

void Bullet::Update(float dt)
{
    if (!IsActive)
        return;

    Position = Vector2Add(Position, Vector2Scale(Direction, Speed * dt));
}

void Bullet::Draw()
{
    if (!IsActive)
        return;

    GameObject::Draw();
}