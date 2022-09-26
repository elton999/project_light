#ifndef CAMERA_SHAKE_H
#define CAMERA_SHAKE_H

#include "../Observer/IObserver.h"
class Scene;

class CameraShake : public IObserver
{
private:
    const int SHAKE_MAGINTUDE = 5;

    const float TIME_OF_SHAKE = 0.17f;
    float timerShake = 0;

    Scene *_scene;

public:
    CameraShake(Scene *scene) { _scene = scene; }

    void Update(float dt);
    void virtual Notify() override;
};

#endif // CAMERA_SHAKE_H