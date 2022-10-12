#include "../../Observer/IObserver.h"
#include "Collectable.h"
#include "../../Scene/Scene.h"

void DestroyCollectable::Notify()
{
    Player *player = _collectable->GetScene()->GetPlayer();
    player->PlayerBackpack->Add(_collectable);

    _collectable->SetActive(false);
}