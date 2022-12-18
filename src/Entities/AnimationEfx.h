#ifndef ANIMATION_EFX_H
#define ANIMATION_EFX_H

#include "SpriteAnimation.h"

class AnimationEfx : public SpriteAnimation
{
public:
    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;
    void StartAnimation();
    bool IsAnimationFinished();
};

#endif // ANIMATION_EFX_H