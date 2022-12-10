#ifndef PLAYER_BACKPACK_H
#define PLAYER_BACKPACK_H

#include "Collectables/Collectable.h"
#include "../Scene/HitBox.h"

class Backpack
{
private:
    Collectable *_collectable;
    bool _hasItem{false};

public:
    bool HasItem() { return _hasItem; }
    void Add(Collectable *collectable);
    void Remove();
    Collectable *GetItem();
    bool UseItem(HitBox *hitBox);
};

#endif // PLAYER_BACKPACK_H