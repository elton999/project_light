#include "../../Observer/IObserver.h"
#include "Collectable.h"

void DestroyCollectable::Notify()
{
    _collectable->SetActive(false);
}