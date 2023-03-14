#ifndef SWITCH_CAMERA_TARGET
#define SWITCH_CAMERA_TARGET

#include "../Observer/IObserver.h"
#include "ICameraTarget.h"
#include "Scene.h"

class SwitchCameraTarget : public IObserver
{

private:
    ICameraTarget *_target;
    Scene *_scene;

public:
    SwitchCameraTarget(ICameraTarget *target, Scene *scene)
    {
        _target = target;
        _scene = scene;
    }
    virtual void Notify() override { _scene->Target = _target; }
};

#endif // SWITCH_CAMERA_TARGET