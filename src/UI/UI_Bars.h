#ifndef UI_BARS_H
#define UI_BARS_H

#include "../Entities/GameObject.h"
#include "../Entities/Player.h"

class UI_Bars : public GameObject
{
private:
    Texture2D _sprite{};

public:
    virtual void Start() override;
    virtual void Draw() override;
};

#endif