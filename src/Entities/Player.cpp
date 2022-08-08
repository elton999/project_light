#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "GameObject.h"

void Player::Start()
{
    Size = {32, 32};
    Origin = {16, 16};
    Position = {200, 200};
}

void Player::Update(float dt)
{
    GameObject::Update(dt);

    Vector2 direction = {0, 0};

    if (IsKeyDown(KEY_A))
        direction.x = -1;
    if (IsKeyDown(KEY_D))
        direction.x = 1;

    if (IsKeyDown(KEY_W))
        direction.y = -1;
    if (IsKeyDown(KEY_S))
        direction.y = 1;

    direction = Vector2Normalize(direction);

    float speed = 40.0f;
    Vector2 velocity = Vector2Scale(direction, speed * dt);
    Position = Vector2Add(Position, velocity);

    LightAngle = atan2f(Position.x - GetMouseX(), Position.y - GetMouseY()) * RAD2DEG;
    LightAngle += 180.0f;
}

void Player::Draw()
{
    DrawCircleSector(Position, LightDistance, LightAngle + 45.0f, LightAngle - 45.0f, LightSegment, YELLOW);
    GameObject::Draw();
}