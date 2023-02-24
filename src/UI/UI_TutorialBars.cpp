#include "UI_TutorialBars.h"

void UI_TutorialBars::Draw()
{
    DrawRectangle((int)_positionBar1.x, (int)_positionBar1.y, (int)_size.x, (int)_size.y, BLACK);
    DrawRectangle((int)_positionBar2.x, (int)_positionBar2.y, (int)_size.x, (int)_size.y, BLACK);
}