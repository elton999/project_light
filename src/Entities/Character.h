#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "raylib.h"

class Character : public GameObject
{
public:
    Texture2D Sprite;
    int SpriteWidth{};
    float Scale{1}, Rotation{1};

    void Animation(float dt);
    virtual void Draw() override;
};

#endif