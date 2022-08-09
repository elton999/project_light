#include "raylib.h"
#include "raymath.h"
#include "Enemy.h"

void Enemy::Start()
{
    Position = {300, 200};
    Origin = {16, 16};
    Size = {32, 32};
    Speed = 60.0f;
}

void Enemy::Update(float dt)
{
    Status = TimeToStop == 0 ? FREEZING : Status;
    Status = TimeToStop == MAX_TIME_TO_STOP ? FOLLOWING : Status;

    if (IsOnLight())
    {
        ColorSquare = RED;
        TimeToStop = Clamp(TimeToStop - dt * SpeedToStop, 0, MAX_TIME_TO_STOP);
    }
    else
    {
        ColorSquare = GREEN;
        TimeToStop = Clamp(TimeToStop + dt * SpeedToStop * 0.3f, 0, MAX_TIME_TO_STOP);
    }

    if (Status == FOLLOWING)
    {
        Vector2 direction = Vector2Normalize(Vector2Subtract(Player->Position, Position));
        Position = Vector2Add(Position, Vector2Scale(direction, Speed * dt));
    }
}

void Enemy::Draw()
{
    Vector2 barSize{40, 5};
    Vector2 barPos = Vector2Subtract(Position, {barSize.x / 2.0f, 30});
    float barPercent = TimeToStop / MAX_TIME_TO_STOP * barSize.x;

    DrawRectangleV(barPos, barSize, BLACK);
    DrawRectangleV(barPos, Vector2Subtract(barSize, {barPercent, 0}), RED);

    GameObject::Draw();
}

bool Enemy::IsOnLight()
{
    float distance = Vector2Distance(Player->Position, Position);

    if (distance <= Player->LightDistance && Player->LightOn)
    {
        Vector2 pNormalized = Vector2Normalize(Vector2Subtract(Position, Player->Position));

        return Vector2DotProduct(Player->GetLightDirection(), pNormalized) >= cos(Player->LightAngleLength / 2.0f * DEG2RAD);
    }
    return false;
}