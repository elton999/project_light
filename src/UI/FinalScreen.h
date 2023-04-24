#ifndef FINAL_SCREEN_H
#define FINAL_SCREEN_H

#include "../Entities/GameObject.h"

class FinalScreen : public GameObject
{

private:
    bool _isShowing = false;

public:
    virtual void
    Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    void Show();
    void Hide();
};

#endif // FINAL_SCREEN_H