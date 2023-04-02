#include "ChargingEfx.h"
#include "raylib.h"
#include "../Scene/Scene.h"

void ChargingEfx::Start()
{
    Sprite = LoadTexture("resources/efx/powerup_efx.png");
    maxFrames = 12;
    Size = {40, 40};
    Origin = {20, 20};
    SetSizeSprite(40, 40);
}

void ChargingEfx::Update(float dt)
{
    Position = GetScene()->GetPlayer()->Position;
    SpriteAnimation::Update(dt);
}

void ChargingEfx::Draw()
{
    if (!_isShowing)
        return;

    SpriteAnimation::Draw();
}