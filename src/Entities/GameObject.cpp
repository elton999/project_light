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