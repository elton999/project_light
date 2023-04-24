#ifndef FINAL_SCREEN_H
#define FINAL_SCREEN_H

#include "../Entities/GameObject.h"
#include "../Observer/IObserver.h"

class FinalScreen : public GameObject, public IObserver
{

private:
    bool _isShowing = false;

public:
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    virtual void Notify() override { Show(); }

    void Show();
    void Hide();
};

#endif // FINAL_SCREEN_H