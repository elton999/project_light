#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"
#include "GameObject.h"

class Bullet : public GameObject
{
public:
    Texture2D Sprite;
    bool IsActive{false};

    void SetDirection(Vector2 direction) { Direction = direction; }

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

private:
    Vector2 Direction{0, 0};
};

#endif