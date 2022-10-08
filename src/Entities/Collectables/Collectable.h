#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "../GameObject.h"
#include "raylib.h"

class Collectable : public GameObject
{
private:
    Texture2D *Sprite;

    float timerElapsed{0};
    float floatingFactor{0};
    float floatingSpeed{3.0f};
    float floatingDistance{7.0f};

    bool _active{true};

protected:
    Rectangle Source;

public:
    Collectable(Texture2D *sprite) { Sprite = sprite; }

    void SetActive(bool active) { _active = active; }

    void virtual Update(float dt) override;
    void virtual Draw() override;
};

#endif // COLLECTABLE_H