#include "raylib.h"
#include "raymath.h"
#include "../Colors.h"
#include "GameObject.h"
#include "Player.h"
#include "../Scene/Scene.h"

void Player::Start()
{
    Size = {32, 32};
    Origin = {16, 16};
    Position = {180, 180};
    Speed = 80;

    idle = LoadTexture("resources/player.png");
    run = LoadTexture("resources/player_run.png");
    damage = LoadTexture("resources/player_damage.png");
    Sprite = idle;

    FlashLight->SetPlayer(this);
}

void Player::Input()
{
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
        FlashLight->LightOn = !FlashLight->LightOn;
}

void Player::Move(Vector2 direction, float speed)
{
    Vector2 oldPosition = Position;
    GameObject::Move(direction, speed);
    CollisionPos = Position;
    if (CheckCollisionGrid((*TilesData), 15) || CheckCollisionSolids(_scene->GetSolids()))
        CollisionPos = Position = oldPosition;
}

void Player::Push(float dt)
{
    Sprite = damage;
    Right = PushDirection.x < 0;
    Move(PushDirection, SpeedPush * dt);
    SpeedPush = Clamp(SpeedPush - 600 * dt, 0, INFINITY);
}

void Player::Update(float dt)
{
    FlashLight->UpdateLightLogic(dt);

    hitEffectTime -= dt;

    SpriteAnimation::Update(dt);

    Input();

    if (SpeedPush > 0)
    {
        Push(dt);
        return;
    }

    Sprite = Vector2Length(Direction) == 0 ? idle : run;

    if (Direction.x != 0)
        Right = Direction.x > 0;

    Move(Vector2Normalize(Direction), Speed * dt);
}

void Player::Draw()
{
    DrawCircleV(GetCollisionPosition(), CollisionRadius, SHADOW);

    FlashLight->DrawLight(Position);

    Vector2 targetPos = Vector2Scale(FlashLight->GetLightDirection(), LineTargetLength);
    targetPos = Vector2Add(Position, targetPos);
    // DrawLineV(Position, targetPos, GRAY);
    // DrawCircleV(targetPos, 3.0f, GRAY);

    SpriteAnimation::Draw();
}

void Player::Hit()
{
    if (hitEffectTime > 0)
        return;
    HP -= 0.2f;
}

void Player::SetPush(Vector2 direction)
{
    if (hitEffectTime > 0)
        return;
    PushDirection = direction;
    SpeedPush = 300.0f;
    hitEffectTime = HIT_EFFECT_TIME;
}