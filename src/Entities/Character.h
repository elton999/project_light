#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#include "raylib.h"

class Character : public GameObject
{
public:
    Texture2D Sprite;
    bool Right{true};
    int SpriteWidth{};
    float Scale{1}, Rotation{1};
    Color SpriteColor{WHITE};

    void Animation(float dt);

    virtual void Update(float dt) override;
    virtual void Draw() override;

protected:
    Vector2 Direction{0, 0};

    float runningTime{0};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
};

#endif