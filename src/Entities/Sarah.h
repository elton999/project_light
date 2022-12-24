#ifndef SARAH_H
#define SARAH_H
#include "GameObject.h"

class Sarah : public GameObject
{
private:
    Texture2D _sprite;

public:
    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;
};
#endif