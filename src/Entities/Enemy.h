#ifndef ENEMY_H
#define ENEMY_H

#include "SpriteAnimation.h"
#include "Player.h"
#include "CollisionCharacter.h"
#include "AnimationEfx.h"

class Enemy : public SpriteAnimation, public CollisionCharacter
{
public:
    Enemy(tiles *tileData)
    {
        TilesData = tileData;
    }

    enum EnemyStatus
    {
        FREEZING,
        FOLLOWING
    };
    EnemyStatus Status = FREEZING;

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Hit() override;

    void CheckPlayerCollision();
    bool IsInLight();

    void SetOnVisible();
    bool CheckOverlay(Vector2 pos, Vector2 size);
    bool IsVisible();

private:
    AnimationEfx *Efx = new AnimationEfx();

    bool Visible{false};

    const float MAX_TIME_TO_STOP = 20.0f;
    bool IsStopping = true;
    float TimeToStop{0};
    float SpeedToStop{10.0f};

    float HitCoolDown{0};
    float const HIT_COOLDOWN_TIME = 0.1f;

    float DeathExplosion{0};
    float const DEATH_EXPLOSION_TIME = 0.2f;

    Texture2D idle{};
    Texture2D walk{};
    Texture2D freezing{};
};

#endif