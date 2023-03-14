#ifndef HIDE_DIALOGUE_BOX_H
#define HIDE_DIALOGUE_BOX_H

#include "../Observer/IObserver.h"
#include "DialogueBox.h"

class HideDialogueBox : public IObserver
{
private:
    DialogueBox *_dialogueBox;

public:
    HideDialogueBox(DialogueBox *dialogueBox)
    {
        _dialogueBox = dialogueBox;
    }
    void virtual Notify() override { _dialogueBox->Hide(); }
};

#endif // HIDE_DIALOGUE_BOX_H