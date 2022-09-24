#ifndef UI_BARS_H
#define UI_BARS_H

#include "../Entities/GameObject.h"
#include "../Entities/Player.h"

class UI_Bars : public GameObject
{
private:
    Texture2D Sprite{};

public:
    virtual void Start() override
    {
        Sprite = LoadTexture("resources/ui/bars_ui.png");
    }

    virtual void Draw() override;
};

#endif