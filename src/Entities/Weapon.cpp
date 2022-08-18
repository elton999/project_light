#include "GameObject.h"
#include "Player.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Enemy.h"

void Weapon::Start()
{
    Texture2D bulletSprite = LoadTexture("resources/efx/ballet.png");
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        Bullets[i] = new Bullet();
        Bullets[i]->Start();
        Bullets[i]->Sprite = bulletSprite;
    }

    Sprite = LoadTexture("resources/efx/shoot_efx.png");
    Origin = {0, 8};
    Size = {16, 16};
    width = 16;
    height = 16;
}

void Weapon::Update(float dt)
{
    Position = Player->Position;
    if (frame == 2)
        PlayAnimation = false;

    if (PlayAnimation)
        SpriteAnimation::Animation(dt);

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

    if (!PlayAnimation)
        return;

    SpriteAnimation::Draw();
}

void Weapon::Shoot()
{
    if (CurrentBullet == MAX_BULLETS)
        CurrentBullet = 0;

    Bullets[CurrentBullet]->SetDirection(Player->GetLightDirection());
    Bullets[CurrentBullet]->IsActive = true;
    Bullets[CurrentBullet]->Position = Vector2Add(Position, Vector2Scale(Player->GetLightDirection(), 15));

    CurrentBullet++;

    Rotation = -Player->LightAngle + 90;
    PlayAnimation = true;
    frame = 0;
    runningTime = 0;
}