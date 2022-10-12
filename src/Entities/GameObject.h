#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "raylib.h"

// #include "../Scene/Scene.h"
class Scene;

class GameObject
{
protected:
    Scene *_scene;

public:
    Vector2 Position{}, Origin{0, 0}, Size{};
    float Speed{0}, HP{1.0f};
    Color ColorSquare{0, 121, 241, 255};

    virtual void Start();
    virtual void Update(float dt);
    virtual void Draw();

    virtual void Move(Vector2 direction, float speed);
    virtual void Hit() {}

    void SetScene(Scene *scene) { _scene = scene; }
    Scene *GetScene() { return _scene; }
};

#endif