#ifndef LIGHT_CHARGER_H
#define LIGHT_CHARGER_H

#include "GameObject.h"
#include "Player.h"

class LightCharger : public GameObject
{
public:
    LightCharger(Vector2 position, Texture2D *sprite)
    {
        Position = position;
        Sprite = *sprite;
    }
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    bool CheckPlayerOverlap();
    void ChargerPlayerLight(float dt);

private:
    Texture2D Sprite{};
    float Radius{25.0f};
    float CurrentRadius;

    float TimerDt{0};
    float VelocityRadiusAnimation{1.0f};
    float ChargeSpeed{0.2f};
};

#endif