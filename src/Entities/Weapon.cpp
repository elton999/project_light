#include "GameObject.h"
#include "../Scene/Scene.h"
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
        Bullets[i]->SetScene(_scene);
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
    Position = _scene->GetPlayer()->Position;
    if (frame == 2)
        PlayAnimation = false;

    if (PlayAnimation)
        SpriteAnimation::Animation(dt);

    for (auto bullet : Bullets)
    {
        if (bullet->IsActive)
        {
            bullet->Update(dt);
            std::list<Enemy *> enemies = _scene->GetEnemies();
            std::list<Enemy *>::iterator iteratorEnemy = enemies.begin();

            while (iteratorEnemy != enemies.end())
            {
                if ((*iteratorEnemy)->CheckOverlay(bullet->Position, bullet->Size) && (*iteratorEnemy)->IsAlive())
                {
                    bullet->IsActive = false;
                    if ((*iteratorEnemy)->Status == Enemy::FREEZING && (*iteratorEnemy)->HP > 0)
                        (*iteratorEnemy)->Hit();
                }
                ++iteratorEnemy;
            }
        }
    }

    Position = _scene->GetPlayer()->Position;
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

    Player *player = _scene->GetPlayer();
    Bullets[CurrentBullet]->SetDirection(player->FlashLight->GetLightDirection());
    Bullets[CurrentBullet]->IsActive = true;
    Bullets[CurrentBullet]->Position = Vector2Add(Position, Vector2Scale(player->FlashLight->GetLightDirection(), 15));

    CurrentBullet++;

    Rotation = -player->FlashLight->LightAngle + 90;
    PlayAnimation = true;
    frame = 0;
    runningTime = 0;
}