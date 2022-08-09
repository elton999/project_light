#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"

class Weapon : public GameObject
{
public:
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    void SetPlayer(Player &player) { Player = &player; }
    void Shoot();

private:
    Player *Player;

    Bullet *Bullets[3];
    int CurrentBullet{0};
    const int MAX_BULLETS = 3;
};

#endif