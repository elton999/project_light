#include "UI_InputTutorial.h"
#include "../Window.h"

void UI_InputTutorial::Start()
{
    DialogueBox::Start();

    Vector2 spriteOffset{-15, Origin.y + 15};

    keyboardAnimation->Sprite = LoadTexture("resources/ui/keyboard_tutorial.png");
    keyboardAnimation->SetMaxFrames(4);
    keyboardAnimation->SetSizeSprite(31, 26);
    keyboardAnimation->Size = {31, 26};
    keyboardAnimation->Position = {(SCREEN_WIDTH - Size.x) / 2.0f - spriteOffset.x, Position.y - spriteOffset.y};

    mouseAnimation->Sprite = LoadTexture("resources/ui/mouse_tutorial.png");
    mouseAnimation->SetMaxFrames(4);
    mouseAnimation->SetSizeSprite(19, 24);
    mouseAnimation->Size = {19, 24};
    mouseAnimation->Position = {(SCREEN_WIDTH - Size.x) / 2.0f - spriteOffset.x, Position.y - spriteOffset.y};

    Size.y = 40;
}

void UI_InputTutorial::Update(float dt)
{
    if (!IsShowing())
        return;

    _timeShowingKeyboardAnimation -= dt;
    _timeShowingMouseAnimation -= dt;

    DialogueBox::Update(dt);

    keyboardAnimation->Update(dt);
    mouseAnimation->Update(dt);
}

void UI_InputTutorial::Draw()
{
    if (!IsShowing())
        return;

    DialogueBox::Draw();

    if (_timeShowingKeyboardAnimation >= 0)
    {
        keyboardAnimation->Draw();
        SetText("                    Use WASD to move the\n                    Character");
    }
    else if (_timeShowingMouseAnimation >= 0)
    {
        SetText("                    Use the mouse to shoot and\n                    turn on the flashlight");
        mouseAnimation->Draw();
    }
}