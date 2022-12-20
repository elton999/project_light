#ifndef UI_BARS_H
#define UI_BARS_H

#include "../Entities/GameObject.h"
#include "../Entities/Player.h"
#include "../Observer/IObserver.h"

class UI_Bars : public GameObject, public IObserver
{
private:
    Texture2D _sprite{};
    const float MAX_TIME_SHAKE = 1.5f;
    float _shakeTime = 0;

public:
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    virtual void Notify() override { _shakeTime = MAX_TIME_SHAKE; }
};

#endif