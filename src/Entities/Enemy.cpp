#include "raylib.h"
#include "raymath.h"
#include "../Colors.h"
#include "Enemy.h"
#include "AnimationEfx.h"
#include "../Scene/Scene.h"
#include "../Observer/ISubject.h"

void Enemy::Start()
{
    CollisionPos = Position;
    Origin = {16, 16};
    Size = {32, 32};
    Speed = 70.0f;

    Sprite = idle;

    OnHit = new ISubject();
    OnHit->Add(_scene->Freezing);
    OnHit->Add(_scene->Shake);
}

void Enemy::Update(float dt)
{
    SetOnVisible();

    if (!IsVisible())
        return;

    HitCoolDown -= dt;
    if (HP <= 0 || HitCoolDown > 0)
        return;

    SetSizeSprite(32, 32);

    Status = TimeToStop == 0 ? FREEZING : Status;
    Status = TimeToStop == MAX_TIME_TO_STOP ? FOLLOWING : Status;

    bool isInLight = _scene->GetPlayer()->FlashLight->IsPointInLight(Position);
    SpriteAnimation::Update(isInLight ? dt * 0.3f : dt);

    int barProgress = 1;
    if (isInLight)
    {
        barProgress = -1;
        SpriteColor = YELLOW;
    }
    else
        SpriteColor = WHITE;

    TimeToStop = Clamp(TimeToStop + (dt * SpeedToStop * barProgress), 0, MAX_TIME_TO_STOP);

    Direction = {0, 0};
    if (Status == FOLLOWING)
    {
        Direction = Vector2Normalize(Vector2Subtract(_scene->GetPlayer()->Position, Position));
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
    if (!IsVisible() || HP <= 0)
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
}

void Enemy::CheckPlayerCollision()
{
    CollisionPos = Position;
    if (CheckCollisionCharacter(_scene->GetPlayer()->GetCollisionPosition(), _scene->GetPlayer()->CollisionRadius))
    {
        _scene->GetPlayer()->Hit();
        _scene->GetPlayer()->SetPush(Direction);
    }
}

bool Enemy::CheckOverlay(Vector2 pos, Vector2 size)
{
    Rectangle enemyRec = {Position.x, Position.y, Size.x, Size.y};
    Rectangle collisionRec = {pos.x, pos.y, size.x, size.y};
    return CheckCollisionRecs(enemyRec, collisionRec);
}

void Enemy::Hit()
{
    HP -= 1.0f / 3.0f;
    HitCoolDown = HIT_COOLDOWN_TIME;
    SpriteColor = BLACK;

    SetSizeSprite(32 + 6, 32 - 6);

    HitEfx->StartAnimation();
    HitEfx->Position = Position;

    OnHit->Notify();

    if (HP <= 0)
    {
        ExplosionEfx->Position = Position;
        ExplosionEfx->StartAnimation();
    }
}

void Enemy::SetOnVisible()
{
    if (IsVisible())
        Visible = true;
}

bool Enemy::IsVisible()
{
    float x = _scene->GetCameraRec().x;
    float y = _scene->GetCameraRec().y;
    float width = _scene->GetCameraRec().width;
    float height = _scene->GetCameraRec().height;
    return CheckOverlay({x, y}, {width, height});
}