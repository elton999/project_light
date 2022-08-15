#include "GameObject.h"
#include "Ui.h"
#include "raylib.h"
#include "../Colors.h"

void Ui::Draw()
{
    Vector2 barSizeHP = {80, 10};

    DrawRectangleV({0, 0}, barSizeHP, BLACK);
    DrawRectangleV({1, 1}, Vector2SubtractValue({barSizeHP.x * Player->HP, barSizeHP.y}, 2), BLUE);

    Vector2 barSizeLight = {70, 7};
    DrawRectangleV({0, barSizeHP.y}, barSizeLight, BLACK);
    DrawRectangleV({1, barSizeHP.y + 1}, Vector2SubtractValue({barSizeLight.x * Player->LightPower, barSizeLight.y}, 2), YELLOW);
}