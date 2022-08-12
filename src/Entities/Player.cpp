#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Character.h"

void Player::Start()
{
    Size = {32, 32};
    Origin = {16, 16};
    Position = {0, 0};
    Speed = 75.0f;
    Sprite = LoadTexture("resources/player.png");
}

void Player::Update(float dt)
{
    Character::Update(dt);

    Vector2 direction = {0, 0};

    if (IsKeyDown(KEY_A))
        direction.x = -1;
    if (IsKeyDown(KEY_D))
        direction.x = 1;

    if (IsKeyDown(KEY_W))
        direction.y = -1;
    if (IsKeyDown(KEY_S))
        direction.y = 1;

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        LightOn = !LightOn;

    if (LightOn)
        LightPower = Clamp(LightPower - 0.1f * dt, 0, INFINITY);

    if (SpeedPush > 0)
    {
        Move(PushDirection, SpeedPush * dt);
        SpeedPush = Clamp(SpeedPush - 600 * dt, 0, INFINITY);
        return;
    }

    direction = Vector2Normalize(direction);

    Move(direction, Speed * dt);

    LightAngle = atan2f(200 - GetMouseX(), 200 - GetMouseY()) * RAD2DEG;
    LightAngle += 180.0f;
}

void Player::Draw()
{
    float angleLength = LightAngleLength / 2.0f;
    if (IsLightOn())
        DrawCircleSector(Position, LightDistance, LightAngle + angleLength, LightAngle - angleLength, LightSegment, YELLOW);

    Vector2 targetPos = Vector2Add(Position, Vector2Scale(GetLightDirection(), LineTargetLength));
    DrawLineV(Position, targetPos, GRAY);
    DrawCircleV(targetPos, 5.0f, GRAY);

    Character::Draw();
}

void Player::SetPush(Vector2 direction)
{
    PushDirection = direction;
    SpeedPush = 300.0f;
}