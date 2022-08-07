#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

private:
    float LightDistance{100.0f};
    int LightSegment{5};
    float LightAngle{0};
};

#endif