#include "raylib.h"
#include "raymath.h"
#include "../Colors.h"
#include "Player.h"
#include "Character.h"

void Player::Start()
{
    Size = {32, 32};
    Origin = {16, 16};
    Position = {0, 0};
    Speed = 75.0f;

    idle = LoadTexture("resources/player.png");
    run = LoadTexture("resources/player_run.png");
    damage = LoadTexture("resources/player_damage.png");
    Sprite = idle;
}

void Player::Update(float dt)
{
    LightDT += dt * 10;
    Character::Update(dt);

    Direction = {0, 0};

    if (IsKeyDown(KEY_A))
        Direction.x = -1;
    if (IsKeyDown(KEY_D))
        Direction.x = 1;

    if (IsKeyDown(KEY_W))
        Direction.y = -1;
    if (IsKeyDown(KEY_S))
        Direction.y = 1;

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        LightOn = !LightOn;

    if (LightOn)
        LightPower = Clamp(LightPower - 0.1f * dt, 0, INFINITY);

    if (SpeedPush > 0)
    {
        Sprite = damage;
        Right = PushDirection.x < 0;
        Move(PushDirection, SpeedPush * dt);
        SpeedPush = Clamp(SpeedPush - 600 * dt, 0, INFINITY);
        return;
    }

    if (Vector2Length(Direction) == 0)
        Sprite = idle;
    else
        Sprite = run;

    if (Direction.x != 0)
        Right = Direction.x > 0;

    Move(Vector2Normalize(Direction), Speed * dt);

    LightAngle = atan2f(GetScreenWidth() / 2.0f - GetMouseX(), GetScreenHeight() / 2.0f - GetMouseY()) * RAD2DEG;
    LightAngle += 180.0f;
}

void Player::Draw()
{
    float angleLength = LightAngleLength / 2.0f;
    if (IsLightOn())
    {
        Color lightColor = YELLOW;
        if (LightPower <= 0.3f)
            if ((int)LightDT % 4 < 2.f)
                lightColor = BLANK;
        DrawCircleSector(Position, LightDistance, LightAngle + angleLength, LightAngle - angleLength, LightSegment, lightColor);
    }

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