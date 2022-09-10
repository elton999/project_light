#ifndef HIT_BOX_H
#define HIT_BOX_H

#include "Solid.h"
#include "../Observer/ISubject.h"
#include "../Entities/CollisionCharacter.h"

class HitBox : public Solid, ISubject
{
public:
    HitBox(Rectangle solidRec) : Solid(solidRec) {}
    void UpdateCheckCollision(CollisionCharacter character);
};

#endif // HIT_BOX_H