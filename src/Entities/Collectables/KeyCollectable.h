#ifndef KEY_COLLECTABLE_H
#define KEY_COLLECTABLE_H

#include "../GameObject.h"
#include "raylib.h"

class KeyCollectable : public GameObject
{
private:
    Texture2D *Sprite;
    Rectangle Source;

    float timerElapsed = 0;
    float floatingFactor = 0;
    float floatingSpeed = 3.0f;
    float floatingDistance = 7.0f;

public:
    KeyCollectable(Texture2D *sprite) { Sprite = sprite; }

    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;
};

#endif // KEY_COLLECTABLE_H