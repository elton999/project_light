#ifndef UI_H
#define UI_H

#include "GameObject.h"
#include "Player.h"

class Ui : public GameObject
{
public:
    virtual void Draw() override;

    void SetPlayer(Player &player) { Player = &player; }

private:
    Player *Player{};
};

#endif