#ifndef HIT_BOX_H
#define HIT_BOX_H

#include "Solid.h"
#include "../Observer/ISubject.h"
#include "../Entities/CollisionCharacter.h"

class HitBox : public Solid, public ISubject
{
public:
    char nameHitBox;

    HitBox(Rectangle solidRec) : Solid(solidRec) {}
    virtual void UpdateCheckCollision(CollisionCharacter character);
};

#endif // HIT_BOX_H