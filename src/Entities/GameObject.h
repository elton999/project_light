#include "raylib.h"

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject
{
public:
    Vector2 Position{}, Origin{}, Size{};
    float Speed{0}, HP{1.0f};
    Color ColorSquare{0, 121, 241, 255};

    virtual void Start();
    virtual void Update(float dt);
    virtual void Draw();
};

#endif