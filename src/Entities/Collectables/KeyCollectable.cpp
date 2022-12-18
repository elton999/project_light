#include "KeyCollectable.h"

void KeyCollectable::Start()
{
    Size = {16, 16};
    Source = {0, 16, Size.x, Size.y};
    Position = {626, 877};

    collectEfx->Position = Position;
}

void KeyCollectable::Update(float dt)
{
    SetTriggerArea({Position.x, Position.y, Size.x, Size.y});
    Collectable::Update(dt);
}