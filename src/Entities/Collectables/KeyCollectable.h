#ifndef KEY_COLLECTABLE_H
#define KEY_COLLECTABLE_H

#include "Collectable.h"
#include "raylib.h"

class KeyCollectable : public Collectable
{
public:
    KeyCollectable(Texture2D *sprite) : Collectable(sprite, {})
    {
        name = 'KEY';
    }

    void virtual Start() override;
    void virtual Update(float dt) override;
};

#endif // KEY_COLLECTABLE_H