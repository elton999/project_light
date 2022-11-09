#ifndef DOOR_HIT_BOX_H
#define DOOR_HIT_BOX_H

#include "../HitBox.h"
#include "../../Entities/GameObject.h"
#include "../../Entities/Collectables/BridgePartSprite.h"
#include "DisableSolid.h"

class DoorHitBox : public HitBox, public GameObject
{
public:
    DoorHitBox(Rectangle solidRec, char name) : HitBox(solidRec)
    {
        nameHitBox = name;
    }

    virtual void UpdateCheckCollision(CollisionCharacter character) override;
};

#endif // DOOR_HIT_BOX_H