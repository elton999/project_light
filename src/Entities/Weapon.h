#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"
#include "SpriteAnimation.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Weapon : public SpriteAnimation
{
public:
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    void SetPlayer(Player &player) { Player = &player; }
    void SetEnemy(Enemy &enemy) { _enemy = &enemy; }
    void Shoot();

private:
    Player *Player;
    Enemy *_enemy;

    Bullet *Bullets[10];
    int CurrentBullet{0};
    const int MAX_BULLETS = 10;

    bool PlayAnimation{false};
};

#endif