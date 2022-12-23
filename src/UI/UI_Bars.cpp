#include "../Entities/GameObject.h"
#include "../Scene/Scene.h"
#include "UI_Bars.h"
#include "raylib.h"
#include "../Colors.h"
#include <cstdlib>

void UI_Bars::Start()
{
    _sprite = LoadTexture("resources/UI/bars_ui.png");
    Position = {0, 0};
}

void UI_Bars::Update(float dt)
{
    _shakeTime -= dt;
    if (_shakeTime > 0)
    {
        int x = rand() % 2 - 1;
        int y = rand() % 2 - 1;

        Position = {x, y};
        return;
    }

    Position = {0, 0};
}

void UI_Bars::Draw()
{
    Vector2 barSizeHP = {88, 7};

    DrawRectangleV(Vector2Add({34, 9}, Position), barSizeHP, DARK_BLUE);
    float barLifeSize = barSizeHP.x * _scene->GetPlayer()->HP;
    barLifeSize = barLifeSize > 0 && barLifeSize < 1.0f ? 1.0f : barLifeSize;
    DrawRectangleV(Vector2Add({34, 9}, Position), {barLifeSize, barSizeHP.y}, BLUE);

    Vector2 barSizeLight = {69, 8};
    DrawRectangleV(Vector2Add({34, 18}, Position), barSizeLight, DARK_BLUE);
    DrawRectangleV(Vector2Add({34, 18}, Position), {barSizeLight.x * _scene->GetPlayer()->FlashLight->LightPower, barSizeLight.y}, YELLOW);

    DrawTexture(_sprite, Position.x + 2, Position.y + 2, WHITE);
}