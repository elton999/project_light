#include "UI_PlayerLantern.h"
#include "../Scene/Scene.h"

void UI_PlayerLantern::Start()
{
    Sprite = LoadTexture("resources/ui/lantern_ui.png");
}

void UI_PlayerLantern::Draw()
{
    Rectangle source = _scene->GetPlayer()->LightOn ? _spriteOnSource : _spriteOffSource;
    DrawTexturePro(Sprite, source, _spriteDist, Origin, 1.0f, WHITE);
}