#include "BridgePartCollectable.h"

void BridgePartCollectable::Start()
{
    Size = {16, 16};
    Source = {32, 0, Size.x, Size.y};
    Position = {393, 235};
}

void BridgePartCollectable::Update(float dt)
{
    SetTriggerArea({Position.x, Position.y, Size.x, Size.y});
    Collectable::Update(dt);
}