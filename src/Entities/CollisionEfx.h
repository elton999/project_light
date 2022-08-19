#ifndef COLLISION_EFX_H
#define COLLISION_EFX_H

#include "SpriteAnimation.h"

class CollisionEfx : public SpriteAnimation
{
public:
    void virtual Start() override;
    void StartAnimation();
    bool IsAnimationFinished();
};

#endif // COLLISION_EFX_H