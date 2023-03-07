#include "DialogueBox.h"
#include "../Window.h"
#include "raymath.h"

void DialogueBox::Start()
{
    Position = {0, SCREEN_HEIGHT / 2.0f};
    Size = {250, 60};
}

void DialogueBox::Update(float dt)
{
    Origin = Vector2Scale(Size, 0.5f);
    Position = {SCREEN_WIDTH / 2.0f, Position.y};
}

void DialogueBox::Draw()
{
    DrawRectangle((int)Position.x - (int)Origin.x, (int)Position.y - (int)Origin.y, (int)Size.x, (int)Size.y, BLACK);
}