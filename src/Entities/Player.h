#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "raymath.h"

class Player : public GameObject
{
public:
    bool LightOn{true};
    float LightAngle{0};
    float LightAngleLength{50.0f};
    float LightDistance{150.0f};

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    Vector2 GetLightDirection() { return {sin(LightAngle * DEG2RAD), cos(LightAngle * DEG2RAD)}; }

private:
    int LightSegment{5};
};

#endif