#include "raylib.h"
#include "raymath.h"
#include "../Colors.h"
#include "Enemy.h"
#include "AnimationEfx.h"
#include "../Scene/Scene.h"
#include "../Observer/ISubject.h"

void Enemy::Start()
{
    ResetSettings();

    OnHit = new ISubject();
    OnHit->Add(_scene->Freezing);
    OnHit->Add(_scene->Shake);
}

void Enemy::ResetSettings()
{
    CollisionPos = InitialPosition;
    Position = InitialPosition;
    HP = 1.0f;
    Origin = {16, 16};
    Size = {32, 32};
    Speed = 70.0f;

    Sprite = idle;
}

void Enemy::Update(float dt)
{
    SetOnVisible();

    if (!IsVisible())
        return;

    HitCoolDown -= dt;
    if (HP <= 0 || HitCoolDown > 0)
        return;

    SetSizeSprite(Size.x, Size.y);

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
    float playerDistance = 0;
    if (Status == FOLLOWING)
    {
        Direction = Vector2Subtract(_scene->GetPlayer()->Position, Position);
        playerDistance = Vector2LengthSqr(Direction);
        Direction = Vector2Normalize(Direction);

        if (playerDistance > MAX_DISTANCE_TO_TURNING)
            Position = Vector2Add(Position, Vector2Scale(Direction, Speed * dt));
    }

    if (playerDistance > MAX_DISTANCE_TO_TURNING && Direction.x != 0)
        Right = Direction.x > 0;

    Sprite = Status == FREEZING ? freezing : idle;
    if (Vector2Length(Direction) > 0 && playerDistance > MAX_DISTANCE_TO_TURNING)
        Sprite = walk;

    CheckPlayerCollision();
}

void Enemy::Draw()
{
    if (GetScene()->GetPlayer()->IsDead())
        return;

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
    HP -= 0.15f;
    HitCoolDown = HIT_COOLDOWN_TIME;
    SpriteColor = BLACK;

    SetSizeSprite(
        Size.x + HIT_SPRITE_DISTORTION_FACTOR,
        Size.y - HIT_SPRITE_DISTORTION_FACTOR);

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