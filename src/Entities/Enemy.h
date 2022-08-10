#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject
{
public:
    Enemy(Player &player) { Player = &player; }

    enum EnemyStatus
    {
        FREEZING,
        FOLLOWING
    };
    EnemyStatus Status = FREEZING;

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Hit() override;

    void CheckPlayerCollision();
    bool IsInLight();
    bool CheckOverlay(Vector2 pos, Vector2 size);

private:
    Player *Player{};

    const float MAX_TIME_TO_STOP = 20.0f;
    bool IsStopping = true;
    float TimeToStop{0};
    float SpeedToStop{10.0f};

    Vector2 Direction{0, 0};
};

#endif