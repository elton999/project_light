#include "Backpack.h"

void Backpack::Add(Collectable *collectable)
{
    _hasItem = true;
    _collectable = collectable;
    OnCollectItem->Notify();
}

void Backpack::Remove() { _hasItem = false; }

Collectable *Backpack::GetItem() { return _collectable; }

bool Backpack::UseItem(HitBox *hitBox)
{
    if (!HasItem())
        return false;

    if (hitBox->nameHitBox != GetItem()->name)
        return false;

    Remove();
    return true;
}