#include "Backpack.h"

void Backpack::Add(Collectable *collectable)
{
    HasItem = true;
    _collectable = collectable;
}

void Backpack::Remove() { HasItem = false; }

Collectable *Backpack::GetItem() { return _collectable; }

bool Backpack::OpenDoor(HitBox *hitBox)
{
    if (!HasItem)
        return false;

    if (hitBox->nameHitBox != GetItem()->name)
        return false;

    Remove();
    return true;
}