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

    enum AnimationType
    {
        LOOP,
        FORWARD
    };

    AnimationType AnimationDirection = LOOP;

    void Animation(float dt);

    virtual void Update(float dt) override { Animation(dt); }
    virtual void Draw() override;

    void SetSizeSprite(int x, int y)
    {
        width = x;
        height = y;
    }

protected:
    Vector2 Direction{0, 0};

    float runningTime{0};
    int frame{0};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    int width{32};
    int height{32};
};

#endif