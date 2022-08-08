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
    virtual void Draw() override;
    bool IsOnLight();

private:
    Player *Player{};

    float SpeedToStop{10.0f};
    float TimeToStop{0};
    const float MAX_TIME_TO_STOP = 20.0f;
};

#endif