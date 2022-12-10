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
    // Draw item in the backpack
    Player *player = GetScene()->GetPlayer();
    Backpack *playerBackpack = player->PlayerBackpack;

    DrawTexture(_sprite, Position.x, Position.y, WHITE);

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