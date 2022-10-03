#include "UI_PlayerLantern.h"
#include "../Scene/Scene.h"

void UI_PlayerLantern::Start()
{
    Sprite = LoadTexture("resources/ui/lantern_ui.png");
}

Rectangle UI_PlayerLantern::GetSpriteSource()
{
    if (_scene->GetPlayer()->LightOn)
        return _spriteOnSource;
    return _spriteOffSource;
}

void UI_PlayerLantern::Draw()
{
    DrawTexturePro(Sprite, GetSpriteSource(), _spriteDist, Origin, 1.0f, WHITE);
}