#ifndef UI_CUT_SCENE_BARS
#define UI_CUT_SCENE_BARS

#include "raylib.h"
#include "../Entities/GameObject.h"

class UI_CutSceneBars : public GameObject
{
private:
    Vector2 _size{426.0f, 50.0f};
    Vector2 _positionBar1{0, -50.0f};
    Vector2 _positionBar2{0, 240.0f};

    bool _show{false};
    float _speed{30.0f};

public:
    void virtual Start() override { Show(); }
    void virtual Update(float dt) override;
    void virtual Draw() override;

    void Show() { _show = true; }
    void Hide() { _show = false; }
};

#endif