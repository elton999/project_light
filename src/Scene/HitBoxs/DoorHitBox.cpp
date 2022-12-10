#include "raylib.h"

#include "DoorHitBox.h"
#include "../Scene.h"
#include "../../Entities/Player.h"

void DoorHitBox::UpdateCheckCollision(CollisionCharacter character)
{
    if (!GetActive())
        return;

    if (!CheckCollision(character.GetCollisionPosition(), character.CollisionRadius))
        return;

    Scene *scene = GetScene();
    Player *player = scene->_player;
    Backpack *playerBackpack = player->PlayerBackpack;

    if (!playerBackpack->UseItem(this))
        return;

    Notify();
}