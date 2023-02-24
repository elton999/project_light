#ifndef UI_TUTORIAL_BARS
#define UI_TUTORIAL_BARS

#include "raylib.h"
#include "../Entities/GameObject.h"

class UI_TutorialBars : public GameObject
{
private:
    Vector2 _size{20.0f, 426.0f};
    Vector2 _positionBar1{0, -20f};
    Vector2 _positionBar2{0, 446};

public:
    void virtual Draw();
}

#endif