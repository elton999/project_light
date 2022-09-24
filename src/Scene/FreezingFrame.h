#ifndef FREEZING_FRAME_H
#define FREEZING_FRAME_H

#include "../Observer/IObserver.h"

class FreezingFrame : public IObserver
{
private:
    float _timerFreezing = 0;

public:
    const float FREEZING_TIME = .15f;
    void Update(float dt);
    bool IsFreezing();
    void virtual Notify() override;
};

#endif // FREEZING_FRAME_H