#ifndef DISABLE_SOLID_H
#define DISABLE_SOLID_H

#include "../Solid.h"
#include "../../Observer/IObserver.h"

class DisableSolid : public IObserver
{
private:
    Solid *_solid;

public:
    DisableSolid(Solid *solid) { _solid = solid; }

    virtual void Notify() override { _solid->SetActive(false); }
};

#endif // DISABLE_SOLID_H