#ifndef UI_CUT_SCENE_BARS
#define UI_CUT_SCENE_BARS

#include "raylib.h"
#include "../Entities/GameObject.h"
#include "../Observer/ISubject.h"

class UI_CutSceneBars : public GameObject
{
private:
    Vector2 _size{426.0f, 50.0f};
    Vector2 _positionBar1{0, -50.0f};
    Vector2 _positionBar2{0, 240.0f};

    bool _show{false};
    float _speed{50.0f};

public:
    ISubject *OnShowCutSceneBars = new ISubject();
    ISubject *OnHideCutSceneBars = new ISubject();

    void virtual Update(float dt) override;
    void virtual Draw() override;

    void Show();
    void Hide();
};

#endif