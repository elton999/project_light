#include "GameObject.h"
#include "Ui.h"
#include "raylib.h"
#include "../Colors.h"

void Ui::Draw()
{
    Vector2 barSizeHP = {88, 7};

    DrawRectangleV({34, 9}, barSizeHP, DARK_BLUE);
    DrawRectangleV({34, 9}, {barSizeHP.x * Player->HP, barSizeHP.y}, BLUE);

    Vector2 barSizeLight = {69, 8};
    DrawRectangleV({34, 18}, barSizeLight, DARK_BLUE);
    DrawRectangleV({34, 18}, {barSizeLight.x * Player->LightPower, barSizeLight.y}, YELLOW);

    DrawTexture(Sprite, 2, 2, WHITE);
}