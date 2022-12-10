#include "GameObject.h"
#include "../Scene/Scene.h"
#include "Player.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Enemy.h"
#include "raymath.h"

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
    _weaponSprite = LoadTexture("resources/weapon.png");
    Origin = {0, 8};
    Size = {16, 16};
    width = 16;
    height = 16;
}

void Weapon::Update(float dt)
{
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

            for (Enemy *enemy : enemies)
            {
                if (enemy->CheckOverlay(bullet->Position, bullet->Size) && enemy->IsAlive())
                {
                    bullet->IsActive = false;
                    if (enemy->Status == Enemy::FREEZING && enemy->HP > 0)
                        enemy->Hit();
                }
            }
        }
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        Shoot();
}

void Weapon::Shoot()
{
    if (CurrentBullet == MAX_BULLETS)
        CurrentBullet = 0;

    Player *player = _scene->GetPlayer();
    Bullets[CurrentBullet]->SetDirection(player->FlashLight->GetLightDirection());
    Bullets[CurrentBullet]->IsActive = true;
    Bullets[CurrentBullet]->Position = Vector2Add(Position, Vector2Scale(player->FlashLight->GetLightDirection(), 25));

    CurrentBullet++;

    Rotation = -player->FlashLight->LightAngle + 90;
    PlayAnimation = true;
    frame = 0;
    runningTime = 0;
}

void Weapon::Draw()
{
    Player *player = _scene->GetPlayer();

    if (player->IsDead())
        return;

    float rotation = -player->FlashLight->LightAngle + 90;

    Vector2 weaponPosition = {player->Position.x, player->Position.y};
    weaponPosition = Vector2Add(weaponPosition, Vector2Scale(player->FlashLight->GetLightDirection(), 15));
    _weaponDest.x = weaponPosition.x;
    _weaponDest.y = weaponPosition.y;

    Vector2 playerPositionDot = Vector2Subtract(weaponPosition, player->Position);
    playerPositionDot = Vector2Normalize({playerPositionDot.x, 0});
    Vector2 weaponPositionDot = Vector2Normalize({weaponPosition.x, 0});

    _weaponSource.height = 8 * Vector2DotProduct(playerPositionDot, weaponPositionDot);

    DrawTexturePro(_weaponSprite, _weaponSource, _weaponDest, _weaponOrigin, rotation, WHITE);

    Position = Vector2Scale(player->FlashLight->GetLightDirection(), 25);
    Position = Vector2Add(_scene->GetPlayer()->Position, Position);

    for (auto bullet : Bullets)
        bullet->Draw();

    if (!PlayAnimation)
        return;

    SpriteAnimation::Draw();
}