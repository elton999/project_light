#include "raylib.h"
#include "raymath.h"
#include "../Colors.h"
#include "GameObject.h"
#include "Player.h"
#include "../Scene/Scene.h"

void Player::Start()
{
    idle = LoadTexture("resources/player.png");
    run = LoadTexture("resources/player_run.png");
    damage = LoadTexture("resources/player_damage.png");
    death = LoadTexture("resources/player_death.png");

    ResetSettings();

    FlashLight->SetPlayer(this);
}

void Player::ResetSettings()
{
    Size = {32, 32};
    Origin = {16, 16};
    Position = {180, 180};
    Speed = 80;
    Sprite = idle;
    HP = 1.0f;

    AnimationDirection = LOOP;
    IsPlayingDeathAnimation = false;

    GetScene()->Target = this;
}

void Player::Input()
{
    Direction = {0, 0};

    if (IsDead())
    {
        if (IsKeyPressed(KEY_SPACE))
            OnRestartGame->Notify();
        return;
    }

    if (!InputIsEnabled)
        return;

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
    SpeedPush = Clamp(SpeedPush - PUSH_FORCE * dt, 0, INFINITY);
}

void Player::Update(float dt)
{
    _totalTime += dt;

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
    if (!IsDead())
    {
        DrawCircleV(GetCollisionPosition(), CollisionRadius, SHADOW);
        Vector2 targetPos = Vector2Scale(FlashLight->GetLightDirection(), LineTargetLength);
        targetPos = Vector2Add(Position, targetPos);
    }

    // blip effect
    SpriteColor = WHITE;
    if (hitEffectTime > 0)
        SpriteColor = fmodf(_totalTime, 0.4f) < 0.2f ? WHITE : BLANK;

    DrawDeathEffect();

    SpriteAnimation::Draw();
}

void Player::DrawDeathEffect()
{
    if (!IsDead())
        return;

    int width = 430;
    _heightRectangleDeathEffect--;

    if (_heightRectangleDeathEffect < 0)
        _heightRectangleDeathEffect = 0;

    DrawRectangle((int)Position.x - width / 2, (int)Position.y - _heightRectangleDeathEffect / 2, width, _heightRectangleDeathEffect, WHITE);
}

void Player::Hit()
{
    if (hitEffectTime > 0)
        return;

    if (!IsDead())
    {
        HP -= 0.2f;

        OnHit->Notify();
        if (IsDead())
            OnDeath->Notify();

        return;
    }

    if (!IsPlayingDeathAnimation)
        _heightRectangleDeathEffect = HEIGHT_RECTANGLE_DEATH_EFFECT;

    IsPlayingDeathAnimation = true;
    AnimationDirection = FORWARD;
    Sprite = death;
}

void Player::SetPush(Vector2 direction)
{
    if (IsDead())
        return;

    if (hitEffectTime > 0)
        return;

    PushDirection = direction;
    SpeedPush = 300.0f;
    hitEffectTime = HIT_EFFECT_TIME;
}