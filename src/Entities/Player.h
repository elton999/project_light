#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "SpriteAnimation.h"
#include "CollisionCharacter.h"
#include "Backpack.h"
#include "PlayerFlashLight.h"
#include "raymath.h"

class Player : public SpriteAnimation, public CollisionCharacter
{
private:
    Vector2 PushDirection{0, 0};
    float SpeedPush{0};

    Texture2D idle{};
    Texture2D run{};
    Texture2D damage{};
    Texture2D death{};

    float const HIT_EFFECT_TIME = 2.0f;
    float hitEffectTime = HIT_EFFECT_TIME;
    float _totalTime{0};

public:
    Player(tiles *tileData)
    {
        TilesData = tileData;
        FlashLight = new PlayerFlashLight();
        PlayerBackpack = new Backpack();
    }

    PlayerFlashLight *FlashLight;
    Backpack *PlayerBackpack;

    float LineTargetLength{50.0f};

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Hit() override;

    virtual void Move(Vector2 direction, float speed) override;
    void Push(float dt);
    void Input();
    void SetPush(Vector2 direction);
};

#endif