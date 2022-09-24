#include "FreezingFrame.h"

bool FreezingFrame::IsFreezing()
{
    return _timerFreezing > 0;
}

void FreezingFrame::Update(float dt)
{
    _timerFreezing -= dt;
}

void FreezingFrame::Notify()
{
    _timerFreezing = FREEZING_TIME;
}
