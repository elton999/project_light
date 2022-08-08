#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject
{
public:
    Enemy(Player &player) { Player = &player; }

    virtual void Start() override;
    virtual void Update(float dt) override;
    bool IsOnLight();

private:
    Player *Player{};
};

#endif