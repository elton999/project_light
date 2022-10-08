#ifndef DESTROY_COLLECTABLE_H
#define DESTROY_COLLECTABLE_H

class Collectable;
#include "../../Observer/IObserver.h"

class DestroyCollectable : public IObserver
{
private:
    Collectable *_collectable;

public:
    DestroyCollectable(Collectable *collectable) { _collectable = collectable; }

    virtual void Notify() override;
};

#endif // DESTROY_COLLECTABLE_H