#include "UI_InputTutorial.h"
#include "../Window.h"
#include "../Scene/Scene.h"

void UI_InputTutorial::Start()
{
    DialogueBox::Start();

    Vector2 spriteOffset{-15, Origin.y + 15};
    Vector2 spritePosition{(SCREEN_WIDTH - Size.x) / 2.0f - spriteOffset.x, Position.y - spriteOffset.y};

    keyboardAnimation->Sprite = LoadTexture("resources/ui/keyboard_tutorial.png");
    keyboardAnimation->SetMaxFrames(4);
    keyboardAnimation->SetSizeSprite(31, 26);
    keyboardAnimation->Size = {31, 26};
    keyboardAnimation->Position = spritePosition;

    mouseAnimation->Sprite = LoadTexture("resources/ui/mouse_tutorial.png");
    mouseAnimation->SetMaxFrames(4);
    mouseAnimation->SetSizeSprite(19, 24);
    mouseAnimation->Size = {19, 24};
    mouseAnimation->Position = spritePosition;

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

    if (_timeShowingMouseAnimation <= 0)
    {
        GetScene()->GetPlayer()->InputIsEnabled = true;
        Hide();
    }
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