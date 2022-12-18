#ifndef COLLECT_EFX_H
#define COLLECT_EFX_H

#include "AnimationEfx.h"
#include "../Observer/IObserver.h"

class CollectEfx : public AnimationEfx, public IObserver
{
public:
    float AnimationTime{0.0f};
    const float MAX_ANIMATION_TIME = 2.0f;

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    virtual void Notify() override { AnimationTime = MAX_ANIMATION_TIME; }
};

#endif // COLLECT_EFX_H