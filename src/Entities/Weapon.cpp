#include "GameObject.h"
#include "Player.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Enemy.h"

void Weapon::Start()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        Bullets[i] = new Bullet();
        Bullets[i]->Start();
    }
}

void Weapon::Update(float dt)
{
    for (auto bullet : Bullets)
    {
        if (bullet->IsActive)
        {
            bullet->Update(dt);
            if (_enemy->CheckOverlay(bullet->Position, bullet->Size))
            {
                if (_enemy->Status == Enemy::FREEZING && _enemy->HP > 0)
                {
                    _enemy->Hit();
                    bullet->IsActive = false;
                }
            }
        }
    }

    Position = Player->Position;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        Shoot();
}

void Weapon::Draw()
{
    for (auto bullet : Bullets)
        bullet->Draw();
}

void Weapon::Shoot()
{
    if (CurrentBullet == MAX_BULLETS)
        CurrentBullet = 0;

    Bullets[CurrentBullet]->SetDirection(Player->GetLightDirection());
    Bullets[CurrentBullet]->IsActive = true;
    Bullets[CurrentBullet]->Position = Position;

    CurrentBullet++;
}