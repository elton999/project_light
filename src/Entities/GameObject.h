#include "raylib.h"

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject
{
public:
    Vector2 Position{}, Origin{}, Size{};

    virtual void Start();
    virtual void Update(float dt);
    virtual void Draw();
};

#endif