#include "HitBox.h"

void HitBox::UpdateCheckCollision(CollisionCharacter character)
{
    if (CheckCollision(character.CollisionPos, character.CollisionRadius))
        Notify();
}