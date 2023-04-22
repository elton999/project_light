#include "DialogueBox.h"
#include "../Window.h"
#include "raymath.h"

void DialogueBox::Start()
{
    Position = {0, SCREEN_HEIGHT / 2.0f};
    Position = Vector2Add(Position, {0, 70});
    Size = {250, 30};

    _font = LoadFont("resources/Kenney Mini.ttf");
    _text = "this is the tutorial of the game";
}

void DialogueBox::Update(float dt)
{
    Origin = Vector2Scale(Size, 0.5f);
    Position = {SCREEN_WIDTH / 2.0f, Position.y};
}

void DialogueBox::Show()
{
    _canShow = true;
}

void DialogueBox::Hide()
{
    _canShow = false;
}

void DialogueBox::SetText(string text)
{
    _text = text;
}

void DialogueBox::Draw()
{
    if (!_canShow)
        return;

    char *text = const_cast<char *>(_text.c_str());
    Vector2 textPosition = {(int)Position.x, (int)Position.y};
    Vector2 textOrigin = {(int)Origin.x - 5, (int)Origin.y - 5};

    DrawRectangle((int)Position.x - (int)Origin.x, (int)Position.y - (int)Origin.y, (int)Size.x, (int)Size.y, BLACK);
    DrawText(text, textPosition.x - textOrigin.x, textPosition.y - textOrigin.y, (int)_fontSize, WHITE);
}