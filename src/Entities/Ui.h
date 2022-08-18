#ifndef UI_H
#define UI_H

#include "GameObject.h"
#include "Player.h"

class Ui : public GameObject
{
public:
    virtual void Start() override
    {
        Sprite = LoadTexture("resources/ui/bars_ui.png");
    }
    virtual void Draw() override;

    void SetPlayer(Player &player) { Player = &player; }

private:
    Player *Player{};
    Texture2D Sprite{};
};

#endif