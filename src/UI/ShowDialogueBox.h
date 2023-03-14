#ifndef SHOW_DIALOGUE_BOX_H
#define SHOW_DIALOGUE_BOX_H

#include "../Observer/IObserver.h"
#include "DialogueBox.h"

class ShowDialogueBox : public IObserver
{
private:
    DialogueBox *_dialogueBox;
    string _text;

public:
    ShowDialogueBox(DialogueBox *dialogueBox, string text)
    {
        _dialogueBox = dialogueBox;
        _text = text;
    }
    void virtual Notify() override
    {
        _dialogueBox->SetText(_text);
        _dialogueBox->Show();
    }
};

#endif // SHOW_DIALOGUE_BOX_H