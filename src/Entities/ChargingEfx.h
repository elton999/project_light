#ifndef CHARGING_EFX_H
#define CHARGING_EFX_H

#include "SpriteAnimation.h"
#include "../Observer/IObserver.h"

class ChargingEfx : public SpriteAnimation
{
private:
    bool _isShowing{false};

public:
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    void SetActive(bool active) { _isShowing = active; }
};

#endif // CHARGING_EFX_H