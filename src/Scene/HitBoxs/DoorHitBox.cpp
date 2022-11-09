#include "raylib.h"

#include "DoorHitBox.h"
#include "../Scene.h"

void DoorHitBox::UpdateCheckCollision(CollisionCharacter character)
{
    if (!GetActive())
        return;

    if (!CheckCollision(character.GetCollisionPosition(), character.CollisionRadius))
        return;

    if (!GetScene()->GetPlayer()->PlayerBackpack->OpenDoor(this))
        return;

    Notify();
}