#ifndef LIGHT_CHARGER_H
#define LIGHT_CHARGER_H

#include "GameObject.h"
#include "Player.h"

class LightCharger : public GameObject
{
public:
    Player *player;
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    bool CheckPlayerOverlap();
    void ChargerPlayerLight(float dt);

private:
    float Radius{45.0f};
    float ChargeSpeed{0.2f};
};

#endif