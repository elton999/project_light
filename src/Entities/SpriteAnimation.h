#ifndef SPRITE_ANIMATION_H
#define SPRITE_ANIMATION_H

#include "GameObject.h"
#include "raylib.h"

class SpriteAnimation : public GameObject
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
    int width{32};
};

#endif