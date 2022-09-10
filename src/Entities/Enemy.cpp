#include "raylib.h"
#include "raymath.h"
#include "../Colors.h"
#include "Enemy.h"

void Enemy::Start()
{
    Position = {-100, -100};
    Origin = {16, 16};
    Size = {32, 32};
    Speed = 100.0f;

    idle = LoadTexture("resources/troll.png");
    walk = LoadTexture("resources/troll_walk.png");
    freezing = LoadTexture("resources/troll_freezing.png");
    Sprite = idle;

    Efx->Start();
}

void Enemy::Update(float dt)
{
    SetOnVisible();

    if (!Efx->IsAnimationFinished())
        Efx->Update(dt);

    HitCoolDown -= dt;
    DeathExplosion -= dt;

    if (HP <= 0 || HitCoolDown > 0)
        return;

    SetSize(32, 32);

    Status = TimeToStop == 0 ? FREEZING : Status;
    Status = TimeToStop == MAX_TIME_TO_STOP ? FOLLOWING : Status;

    Direction = {0, 0};
    SpriteAnimation::Update(IsInLight() ? dt * 0.3f : dt);

    int barProgress = 1;
    if (IsInLight())
    {
        barProgress = -1;
        SpriteColor = YELLOW;
    }
    else
        SpriteColor = WHITE;

    TimeToStop = Clamp(TimeToStop + (dt * SpeedToStop * barProgress), 0, MAX_TIME_TO_STOP);

    if (Status == FOLLOWING)
    {
        Direction = Vector2Normalize(Vector2Subtract(Player->Position, Position));
        Position = Vector2Add(Position, Vector2Scale(Direction, Speed * dt));
    }

    if (Direction.x != 0)
        Right = Direction.x > 0;

    if (Vector2Length(Direction) == 0)
        Sprite = Status == FREEZING ? freezing : idle;
    else
        Sprite = walk;

    CheckPlayerCollision();
}

void Enemy::Draw()
{
    if (DeathExplosion >= 0)
        DrawCircle(Position.x, Position.y, Size.y, BLACK);

    if (HP <= 0)
        return;

    Vector2 barSize{40, 5};
    Vector2 barPos = Vector2Subtract(Position, {barSize.x / 2.0f, 30});
    float barPercent = TimeToStop / MAX_TIME_TO_STOP * barSize.x;
    float barHPPercent = (1.0f - HP) * barSize.x;

    DrawRectangleV(Vector2Subtract(barPos, {0, 5}), barSize, BLACK);
    DrawRectangleV(Vector2Subtract(barPos, {-1, 4}), Vector2Subtract(barSize, {barHPPercent + 2, 2}), GREEN);

    DrawRectangleV(barPos, barSize, BLACK);
    DrawRectangleV(Vector2AddValue(barPos, 1), Vector2Subtract(barSize, {barPercent + 2, 2}), RED);

    SpriteAnimation::Draw();
    Efx->Draw();
}

void Enemy::CheckPlayerCollision()
{
    CollisionPos = Position;
    if (CheckCollisionCharacter(Player->GetCollisionPosition(), Player->CollisionRadius))
    {
        Player->Hit();
        Player->SetPush(Direction);
    }
}

bool Enemy::CheckOverlay(Vector2 pos, Vector2 size)
{
    return CheckCollisionRecs({pos.x, pos.y, size.x, size.y}, {Position.x, Position.y, Size.x, Size.y});
}

void Enemy::Hit()
{
    HP -= 1.0f / 3.0f;
    HitCoolDown = HIT_COOLDOWN_TIME;
    SpriteColor = BLACK;

    SetSize(32 + 6, 32 - 6);

    Efx->StartAnimation();
    Efx->Position = Position;

    if (HP <= 0)
        DeathExplosion = DEATH_EXPLOSION_TIME;
}

bool Enemy::IsInLight()
{
    float distance = Vector2Distance(Player->Position, Position);

    if (distance <= Player->LightDistance && Player->IsLightOn())
    {
        Vector2 pNormalized = Vector2Normalize(Vector2Subtract(Position, Player->Position));
        return Vector2DotProduct(Player->GetLightDirection(), pNormalized) >= cos(Player->LightAngleLength / 2.0f * DEG2RAD);
    }
    return false;
}

void Enemy::SetOnVisible()
{
    if (IsVisible())
        Visible = true;
}