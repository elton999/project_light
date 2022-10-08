#include "KeyCollectable.h"

void KeyCollectable::Start()
{
    Size = {16, 16};
    Source = {0, Size.y, Size.x, Size.y};
    Position = {100, 300};
}

void KeyCollectable::Update(float dt)
{
    SetTriggerArea({Position.x, Position.y, Size.x, Size.y});
    Collectable::Update(dt);
}