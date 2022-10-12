#include "raylib.h"
#include "UI_PlayerBackpack.h"
#include "../Scene/Scene.h"
#include "../Entities/Backpack.h"

void UI_PlayerBackpack::Start()
{
    _sprite = LoadTexture("resources/UI/backpack_ui.png");
    Position = {211, 2};
}

void UI_PlayerBackpack::Draw()
{
    DrawTexture(_sprite, Position.x, Position.y, WHITE);

    // Draw item in the backpack
    Player *player = GetScene()->GetPlayer();
    if (!player->PlayerBackpack->HasItem)
        return;

    Backpack *playerBackpack = player->PlayerBackpack;

    DrawTexturePro(
        *playerBackpack->GetItem()->Sprite,
        playerBackpack->GetItem()->Source,
        Dest,
        Origin,
        1.0f,
        WHITE);
}