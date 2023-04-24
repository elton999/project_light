#ifndef SARAH_H
#define SARAH_H
#include "GameObject.h"
#include "../Scene/HitBox.h"

class Sarah : public GameObject, public HitBox
{
private:
    Texture2D _sprite;

public:
    Sarah() : HitBox({0, 0, 0, 0}) {}

    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;
};
#endif