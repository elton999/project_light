#ifndef DIALOGUE_BOX_H
#define DIALOGUE_BOX_H

#include "raylib.h"
#include "../Entities/GameObject.h"
#include <string>
using namespace std;

class DialogueBox : public GameObject
{
private:
    Font _font;
    float _fontSize{8.0f};
    string _text;
    bool _canShow = true;

public:
    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;
};

#endif // DIALOGUE_BOX_H