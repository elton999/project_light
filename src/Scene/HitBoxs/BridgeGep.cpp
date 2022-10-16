#include "raylib.h"

#include "BridgeGep.h"
#include "../Scene.h"

void BridgeGep::UpdateCheckCollision(CollisionCharacter character)
{
    if (!GetActive())
        return;

    if (!CheckCollision(character.GetCollisionPosition(), character.CollisionRadius))
        return;

    if (!GetScene()->GetPlayer()->PlayerBackpack->OpenDoor(this))
        return;

    TraceLog(LOG_INFO, "open");

    Notify();
}