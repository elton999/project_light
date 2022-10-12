#include "../Entities/GameObject.h"
#include "../Scene/Scene.h"
#include "UI_Bars.h"
#include "raylib.h"
#include "../Colors.h"

void UI_Bars::Start()
{
    _sprite = LoadTexture("resources/UI/bars_ui.png");
}

void UI_Bars::Draw()
{
    Vector2 barSizeHP = {88, 7};

    DrawRectangleV({34, 9}, barSizeHP, DARK_BLUE);
    DrawRectangleV({34, 9}, {barSizeHP.x * _scene->GetPlayer()->HP, barSizeHP.y}, BLUE);

    Vector2 barSizeLight = {69, 8};
    DrawRectangleV({34, 18}, barSizeLight, DARK_BLUE);
    DrawRectangleV({34, 18}, {barSizeLight.x * _scene->GetPlayer()->LightPower, barSizeLight.y}, YELLOW);

    DrawTexture(_sprite, 2, 2, WHITE);
}