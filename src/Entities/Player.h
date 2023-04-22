#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "SpriteAnimation.h"
#include "CollisionCharacter.h"
#include "Backpack.h"
#include "PlayerFlashLight.h"
#include "raymath.h"
#include "../Observer/ISubject.h"
#include "../Scene/IResetScene.H"
#include "../Scene/ICameraTarget.h"

class Player : public SpriteAnimation, public CollisionCharacter, public IResetScene, public ICameraTarget
{
private:
    Vector2 PushDirection{0, 0};
    float SpeedPush{0};

    Texture2D idle{};
    Texture2D run{};
    Texture2D damage{};
    Texture2D death{};

    float const HIT_EFFECT_TIME = 2.0f;
    float hitEffectTime{0};
    float _totalTime{0};
    int const PUSH_FORCE = 600;
    int const HEIGHT_RECTANGLE_DEATH_EFFECT = 20;
    int _heightRectangleDeathEffect = 20;
    bool IsPlayingDeathAnimation = false;

    void DrawDeathEffect();

public:
    Player(tiles *tileData)
    {
        TilesData = tileData;
        FlashLight = new PlayerFlashLight();
        PlayerBackpack = new Backpack();
    }

    ISubject *OnHit = new ISubject();
    ISubject *OnRestartGame = new ISubject();
    ISubject *OnDeath = new ISubject();

    PlayerFlashLight *FlashLight;
    Backpack *PlayerBackpack;

    float LineTargetLength{50.0f};

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Hit() override;

    virtual Vector2 GetTargetPosition() override { return Position; }
    virtual float GetBasePositionY() { return GetCollisionPosition().y + CollisionRadius * 2; }

    virtual void ResetSettings() override;

    virtual void Move(Vector2 direction, float speed) override;
    void Push(float dt);
    void Input();
    void SetPush(Vector2 direction);
};

#endif