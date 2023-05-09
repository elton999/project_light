#include "raylib.h"
#include "raymath.h"
#include "UI_PlayerBackpack.h"
#include "../Scene/Scene.h"
#include "../Entities/Backpack.h"

void UI_PlayerBackpack::Start()
{
    _sprite = LoadTexture("resources/UI/backpack_ui.png");
    Position = {211, 2};

    Player *player = GetScene()->GetPlayer();
    Backpack *playerBackpack = player->PlayerBackpack;
    playerBackpack->OnCollectItem->Add(this);
}

void UI_PlayerBackpack::Update(float dt)
{
    if (_isPlayingEffect)
        _alpha = Clamp(_alpha - dt * _collectItemSpeedEfx, 0, _alpha);

    _isPlayingEffect = _alpha > 0;
}

void UI_PlayerBackpack::Draw()
{
    Player *player = GetScene()->GetPlayer();
    Backpack *playerBackpack = player->PlayerBackpack;

    DrawTexture(_sprite, Position.x, Position.y, WHITE);

    DrawCollectEffect();

    if (!playerBackpack->HasItem())
        return;

    // Draw item in the backpack
    DrawTexturePro(
        *playerBackpack->GetItem()->Sprite,
        playerBackpack->GetItem()->Source,
        Dest,
        Origin,
        1.0f,
        WHITE);
}

void UI_PlayerBackpack::Notify()
{
    _isPlayingEffect = true;
    _alpha = _maxAlphaValue;
}

void UI_PlayerBackpack::DrawCollectEffect()
{
    if (!_isPlayingEffect)
        return;

    float multiplierFactor = _alpha / _collectItemSizeMultiplier + 1;

    float width = _sprite.width * multiplierFactor;
    float height = _sprite.height * multiplierFactor;

    float positionX = Position.x - width / 2.0f + _sprite.width / 2.0f;
    DrawRectangleLines(positionX, Position.y, width, height, (Color){255, 255, 255, _alpha});
}