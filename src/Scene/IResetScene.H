#ifndef I_RESET_SCENE_H
#define I_RESET_SCENE_H
#include "../Observer/IObserver.h"

class IResetScene : public IObserver
{
public:
    virtual void ResetSettings() {}
    virtual void Notify() override { ResetSettings(); }
};

#endif // I_RESET_SCENE_H