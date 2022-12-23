#ifndef ENEMY_H
#define ENEMY_H

#include "SpriteAnimation.h"
#include "Player.h"
#include "CollisionCharacter.h"
#include "AnimationEfx.h"
#include "../Observer/ISubject.h"
#include "../Scene/IResetScene.H"

class Enemy : public SpriteAnimation, public CollisionCharacter, public IResetScene
{
public:
    Enemy(tiles *tileData, Vector2 position, Texture2D *idleTex, Texture2D *walkTex, Texture2D *freezingTex)
    {
        TilesData = tileData;
        InitialPosition = position;
        Position = position;
        idle = *idleTex;
        walk = *walkTex;
        freezing = *freezingTex;
    }

    Vector2 InitialPosition;
    AnimationEfx *HitEfx;
    AnimationEfx *ExplosionEfx;

    enum EnemyStatus
    {
        FREEZING,
        FOLLOWING
    };
    EnemyStatus Status = FREEZING;

    ISubject *OnHit;

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Hit() override;

    virtual void ResetSettings() override;

    void CheckPlayerCollision();
    bool IsAlive() { return HP > 0; }

    void SetOnVisible();
    bool CheckOverlay(Vector2 pos, Vector2 size);
    bool IsVisible();

private:
    bool Visible{false};

    const float MAX_TIME_TO_STOP = 20.0f;
    const float MAX_DISTANCE_TO_TURNING = 2.0f;
    bool IsStopping = true;
    float TimeToStop{0};
    float SpeedToStop{10.0f};

    float HitCoolDown{0};
    float const HIT_COOLDOWN_TIME = 0.1f;

    Texture2D idle{};
    Texture2D walk{};
    Texture2D freezing{};
};

#endif