#ifndef BRIDGE_GEP_H
#define BRIDGE_GEP_H

#include "../HitBox.h"
#include "../../Entities/GameObject.h"
#include "DisableSolid.h"

class BridgeGep : public HitBox, public GameObject
{
public:
    BridgeGep(Rectangle solidRec, Solid *wall) : HitBox(solidRec)
    {
        nameHitBox = 'BRIDGE_PART';

        Add(new DisableSolid(wall));
        Add(new DisableSolid(this));
    }

    virtual void UpdateCheckCollision(CollisionCharacter character) override;
};

#endif // BRIDGE_GEP_H