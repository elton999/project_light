#ifndef PLAYER_BACKPACK_H
#define PLAYER_BACKPACK_H

#include "Collectables/Collectable.h"
#include "../Scene/HitBox.h"

class Backpack
{
private:
    Collectable *_collectable;

public:
    bool HasItem{false};

    void Add(Collectable *collectable);
    void Remove();
    Collectable *GetItem();
    bool OpenDoor(HitBox *hitBox);
};

#endif // PLAYER_BACKPACK_H