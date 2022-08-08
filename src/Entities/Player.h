#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
    float LightAngle{0};
    float LightAngleLength{50.0f};
    float LightDistance{150.0f};

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

private:
    int LightSegment{5};
};

#endif