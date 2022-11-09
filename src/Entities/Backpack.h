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

    void Add(Collectable *collectable)
    {
        HasItem = true;
        _collectable = collectable;
    }

    void Remove() { HasItem = false; }

    Collectable *GetItem() { return _collectable; }

    bool OpenDoor(HitBox *hitBox)
    {
        if (!HasItem)
            return false;

        if (hitBox->nameHitBox != _collectable->name)
            return false;

        Remove();
        return true;
    }
};

#endif // PLAYER_BACKPACK_H