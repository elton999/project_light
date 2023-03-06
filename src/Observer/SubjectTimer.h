#ifndef SUBJECT_TIMER
#define SUBJECT_TIMER

#include "ISubject.h"
#include "../Entities/GameObject.h"
#include "../Scene/Scene.h"

class SubjectTimer : public GameObject
{
private:
    float _timer;
    bool _isDone = false;

public:
    ISubject *OnRiseEvent = new ISubject();

    SubjectTimer(float timer, Scene *scene)
    {
        _timer = timer;
        scene->AddUI(this);
    }

    void virtual Update(float dt) override
    {
        if (_isDone)
            return;

        _timer -= dt;
        if (_timer <= 0)
            _isDone = true;

        OnRiseEvent.Notify();
    }
};

#endif