#include "FinalScreen.h"
#include "../Window.h"

void FinalScreen::Start()
{
}

void FinalScreen::Update(float dt)
{
}

void FinalScreen::Draw()
{
    if (!_isShowing)
        return;

    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
    DrawText("Thank you for playing", 20, 10, 20, WHITE);
    DrawText("Especial Thanks", 20, 40, 15, WHITE);
    DrawText("Dad & Mom", 20, 60, 11, WHITE);
    DrawText("Just another Game by", 20, 80, 15, WHITE);
    DrawText("Elton Silva", 20, 100, 11, WHITE);
}

void FinalScreen::Hide() { _isShowing = false; }

void FinalScreen::Show() { _isShowing = true; }