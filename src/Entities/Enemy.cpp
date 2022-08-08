#include "raylib.h"
#include "raymath.h"
#include "Enemy.h"

void Enemy::Start()
{
    Position = {300, 200};
    Origin = {16, 16};
    Size = {32, 32};
}

void Enemy::Update(float dt)
{
    if (IsOnLight())
        ColorSquare = RED;
    else
        ColorSquare = GREEN;
}

bool Enemy::IsOnLight()
{
    float distance = Vector2Distance(Player->Position, Position);

    if (distance <= Player->LightDistance)
    {
        Vector2 direction = {sin(Player->LightAngle * DEG2RAD), cos(Player->LightAngle * DEG2RAD)};
        Vector2 pNormalized = Vector2Normalize(Vector2Subtract(Position, Player->Position));

        return Vector2DotProduct(direction, pNormalized) >= cos(45.0f * DEG2RAD);
    }
    return false;
}