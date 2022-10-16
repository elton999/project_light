#include "HitBox.h"

void HitBox::UpdateCheckCollision(CollisionCharacter character)
{
    if (CheckCollision(character.GetCollisionPosition(), character.CollisionRadius))
        Notify();
}