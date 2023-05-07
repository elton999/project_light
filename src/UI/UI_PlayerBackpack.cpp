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
        _alpha = Clamp(_alpha - dt * 200, 0, _alpha);

    if (_alpha == 0)
        _isPlayingEffect = false;
}

void UI_PlayerBackpack::Draw()
{
    // Draw item in the backpack
    Player *player = GetScene()->GetPlayer();
    Backpack *playerBackpack = player->PlayerBackpack;

    DrawTexture(_sprite, Position.x, Position.y, WHITE);

    float width = _sprite.width * (_alpha / 50.0f + 1);
    if (_isPlayingEffect)
        DrawRectangleLines(Position.x - width / 2.0f + _sprite.width / 2.0f, Position.y, width, _sprite.height * (_alpha / 50.0f + 1), (Color){255, 255, 255, _alpha});

    if (!playerBackpack->HasItem())
        return;

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
    _alpha = 255.0f;
}