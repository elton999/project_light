#ifndef SUBJECT_TIMER
#define SUBJECT_TIMER

#include "ISubject.h"
#include "../Entities/GameObject.h"
#include "../Scene/Scene.h"

class SubjectTimer : public GameObject, public IObserver
{
private:
    float _timer;
    bool _isDone = false;
    bool _isStarted = false;

public:
    ISubject *OnRiseEvent = new ISubject();

    SubjectTimer(float timer) { _timer = timer; }

    void virtual Update(float dt) override
    {
        if (_isDone)
            return;

        if (!_isStarted)
            return;

        _timer -= dt;
        if (_timer <= 0)
        {
            _isDone = true;
            OnRiseEvent->Notify();
        }
    }

    void virtual Notify() override { _isStarted = true; }
};

#endif