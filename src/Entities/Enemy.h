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

    enum EnemyStatus
    {
        FREEZING,
        FOLLOWING
    };
    EnemyStatus Status = FREEZING;

    const float MAX_TIME_TO_STOP = 20.0f;
    bool IsStopping = true;
    float TimeToStop{0};
    float SpeedToStop{10.0f};
};

#endif