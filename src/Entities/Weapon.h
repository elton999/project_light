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
    void Shoot();

private:
    Texture2D _weaponSprite;
    Rectangle _weaponSource{0, 0, 12, 8};
    Rectangle _weaponDest{0, 0, 12, 8};
    Vector2 _weaponOrigin{0, 4};
    Bullet *Bullets[10];
    int CurrentBullet{0};
    const int MAX_BULLETS = 10;

    bool PlayAnimation{false};
};

#endif