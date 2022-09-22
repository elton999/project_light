#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "SpriteAnimation.h"
#include "CollisionCharacter.h"
#include "raymath.h"

class Player : public SpriteAnimation, public CollisionCharacter
{
private:
    int LightSegment{5};
    float LightDT{0};
    Vector2 PushDirection{0, 0};
    float SpeedPush{0};

    Texture2D idle{};
    Texture2D run{};
    Texture2D damage{};

    float const HIT_EFFECT_TIME = 2.0f;
    float hitEffectTime = HIT_EFFECT_TIME;

public:
    Player(tiles *tileData) { TilesData = tileData; }

    bool LightOn{true};
    float LightAngle{0};
    float LightAngleLength{50.0f};
    float LightDistance{150.0f};
    float LightPower{1.0f};

    float LineTargetLength{50.0f};

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Hit() override;

    virtual void Move(Vector2 direction, float speed) override;
    void Push(float dt);

    void Input();

    Vector2 GetLightDirection() { return {sin(LightAngle * DEG2RAD), cos(LightAngle * DEG2RAD)}; }
    void SetPush(Vector2 direction);

    bool IsLightOn() { return LightOn && LightPower > 0; }
};

#endif