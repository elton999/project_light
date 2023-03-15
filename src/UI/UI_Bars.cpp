#include "../Entities/GameObject.h"
#include "../Scene/Scene.h"
#include "UI_Bars.h"
#include "raylib.h"
#include "raymath.h"
#include "../Colors.h"
#include <cstdlib>

void UI_Bars::Start()
{
    _sprite = LoadTexture("resources/UI/bars_ui.png");
    Position = {0, 0};
}

void UI_Bars::Update(float dt)
{
    _lastHPValue = _scene->GetPlayer()->HP;

    float barSizeHPx = Clamp(_barSizeHPWhite.x - SPEED_BAR_EFFECT * dt, 0, INFINITY);
    _barSizeHPWhite = {barSizeHPx, _barSizeHPWhite.y};

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
    DrawRectangleV(Vector2Add(_barHPPosition, Position), _barSizeHP, DARK_BLUE);
    float barLifeSize = _barSizeHP.x * _scene->GetPlayer()->HP;
    barLifeSize = barLifeSize > 0 && barLifeSize < 1.0f ? 1.0f : barLifeSize;
    DrawRectangleV(Vector2Add(_barHPPosition, Position), _barSizeHPWhite, WHITE);
    DrawRectangleV(Vector2Add(_barHPPosition, Position), {barLifeSize, _barSizeHP.y}, BLUE);

    DrawRectangleV(Vector2Add(_barLightPosition, Position), _barSizeLight, DARK_BLUE);
    DrawRectangleV(Vector2Add(_barLightPosition, Position), {_barSizeLight.x * _scene->GetPlayer()->FlashLight->LightPower, _barSizeLight.y}, YELLOW);

    DrawTexture(_sprite, Position.x + 2, Position.y + 2, WHITE);
}