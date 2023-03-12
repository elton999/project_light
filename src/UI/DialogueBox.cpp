#include "DialogueBox.h"
#include "../Window.h"
#include "raymath.h"

void DialogueBox::Start()
{
    Position = {0, SCREEN_HEIGHT / 2.0f};
    Size = {250, 60};
    _font = LoadFont("resources/Kenney Mini.ttf");
    _text = "this is the tutorial of the game";
}

void DialogueBox::Update(float dt)
{
    Origin = Vector2Scale(Size, 0.5f);
    Position = {SCREEN_WIDTH / 2.0f, Position.y};
}

void DialogueBox::Draw()
{
    if (!_canShow)
        return;

    char *text = const_cast<char *>(_text.c_str());
    DrawRectangle((int)Position.x - (int)Origin.x, (int)Position.y - (int)Origin.y, (int)Size.x, (int)Size.y, BLACK);
    DrawTextPro(_font, text, {std::roundf(Position.x), std::roundf(Position.y)}, {std::roundf(Origin.x), std::roundf(Origin.y)}, 1.0f, (int)_fontSize, 0.0f, WHITE);
}