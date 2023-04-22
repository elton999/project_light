#ifndef UI_INPUT_TUTORIAL
#define UI_INPUT_TUTORIAL

#include "DialogueBox.h"
#include "../Entities/SpriteAnimation.h"

class UI_InputTutorial : public DialogueBox
{
private:
    SpriteAnimation *keyboardAnimation = new SpriteAnimation();
    SpriteAnimation *mouseAnimation = new SpriteAnimation();

    float _timeShowingKeyboardAnimation = 5.0f;
    float _timeShowingMouseAnimation = 10.0f;

public:
    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;
};

#endif // UI_INPUT_TUTORIAL