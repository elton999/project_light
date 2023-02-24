#include "UI_CutSceneBars.h"

void UI_CutSceneBars::Draw()
{
    DrawRectangle((int)_positionBar1.x, (int)_positionBar1.y, (int)_size.x, (int)_size.y, BLACK);
    DrawRectangle((int)_positionBar2.x, (int)_positionBar2.y, (int)_size.x, (int)_size.y, BLACK);
}