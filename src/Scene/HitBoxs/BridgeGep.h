#ifndef BRIDGE_GEP_H
#define BRIDGE_GEP_H

#include "../HitBox.h"
#include "../../Entities/GameObject.h"
#include "../../Entities/Collectables/BridgePartSprite.h"
#include "DisableSolid.h"

class BridgeGep : public HitBox, public GameObject
{
public:
    BridgeGep(Rectangle solidRec, Solid *wall, IObserver *bridgeGepSprite) : HitBox(solidRec)
    {
        nameHitBox = 'BRIDGE_PART';

        Add(new DisableSolid(wall));
        Add(new DisableSolid(this));
        Add(bridgeGepSprite);
    }

    virtual void UpdateCheckCollision(CollisionCharacter character) override;
};

#endif // BRIDGE_GEP_H