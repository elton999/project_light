#ifndef KEY_COLLECTABLE_H
#define KEY_COLLECTABLE_H

#include "../GameObject.h"
#include "raylib.h"

class KeyCollectable : public GameObject
{
private:
    Texture2D *Sprite;
    Rectangle Source;

public:
    KeyCollectable(Texture2D *sprite) { Sprite = sprite; }

    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;
};

#endif // KEY_COLLECTABLE_H