#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "../GameObject.h"
#include "../../Scene/HitBox.h"
#include "DestroyCollectable.h"
#include "raylib.h"

class Collectable : public GameObject, public HitBox
{
private:
    float timerElapsed{0};
    float floatingFactor{0};
    float floatingSpeed{3.0f};
    float floatingDistance{7.0f};

    float shadowMiniSize{2};

public:
    Texture2D *Sprite;
    Rectangle Source;

    char name;

    Collectable(Texture2D *sprite, Rectangle solidRec) : HitBox(solidRec)
    {
        Sprite = sprite;
        DestroyCollectable *destroyCollectable = new DestroyCollectable(this);
        Add(destroyCollectable);
    }

    void virtual Update(float dt) override;
    void virtual Draw() override;
};

#endif // COLLECTABLE_H