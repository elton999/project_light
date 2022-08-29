#include "raylib.h"
#include "raymath.h"
#include "GameObject.h"

void GameObject::Start()
{
    Size = {50, 50};
}

void GameObject::Update(float dt) {}

void GameObject::Draw()
{
    DrawRectangleV(Vector2Subtract(Position, Origin), Size, ColorSquare);
}

void GameObject::Move(Vector2 direction, float speed)
{
    Vector2 velocity = Vector2Scale(direction, speed);
    Position = Vector2Add(Position, velocity);
    Position = {std::roundf(Position.x),
                std::roundf(Position.y)};
}