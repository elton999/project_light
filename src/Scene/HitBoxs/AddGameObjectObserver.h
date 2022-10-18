#ifndef ADD_GAME_OBJECT_OBSERVER_H
#define ADD_GAME_OBJECT_OBSERVER_H

#include "../../Observer/IObserver.h"
#include "../Scene.h"

class AddGameObjectObserver : public IObserver
{
private:
    GameObject *_gameObject;
    Scene *_scene;

public:
    AddGameObjectObserver(GameObject *gameObject, Scene *scene)
    {
        _gameObject = gameObject;
        _scene = scene;
    }

    void virtual Notify() override { _scene->AddBackground(_gameObject); }
};

#endif // ADD_GAME_OBJECT_OBSERVER_H