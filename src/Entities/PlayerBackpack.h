#ifndef PLAYER_BACKPACK_H
#define PLAYER_BACKPACK_H

#include "GameObject.h"
#include "Collectables/Collectable.h"
#include "../Scene/HitBox.h"

class PlayerBackpack : public GameObject
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

    void OpenDoor(HitBox *hitBox)
    {
        if (hitBox->nameHitBox == _collectable->name && HasItem)
        {
            Remove();
        }
    }
};

#endif // PLAYER_BACKPACK_H