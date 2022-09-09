#ifndef I_SUBJECT_H
#define I_SUBJECT_H

#include "IObserver.h"
#include <list>

class ISubject
{
private:
    std::list<IObserver *> _observers;

public:
    void Add(IObserver *observer) { _observers.push_back(observer); }
    void Notify()
    {
        std::list<IObserver *>::iterator iterator = _observers.begin();
        while (iterator != _observers.end())
        {
            (*iterator)->Notify();
            ++iterator;
        }
    }
};
#endif