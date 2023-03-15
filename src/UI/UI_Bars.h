#ifndef UI_BARS_H
#define UI_BARS_H

#include "../Entities/GameObject.h"
#include "../Entities/Player.h"
#include "../Observer/IObserver.h"

class UI_Bars : public GameObject, public IObserver
{
private:
    const float MAX_TIME_SHAKE = 1.5f;
    float SPEED_BAR_EFFECT = 30.0f;

    Texture2D _sprite{};
    float _shakeTime = 0;

    Vector2 _barSizeHP = {88, 7};
    Vector2 _barSizeHPWhite = {88, 7};
    Vector2 _barHPPosition = {34, 9};

    Vector2 _barSizeLight = {69, 8};
    Vector2 _barLightPosition = {34, 18};

    float _lastHPValue = 0;

public:
    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;

    virtual void Notify() override
    {
        _shakeTime = MAX_TIME_SHAKE;
        _barSizeHPWhite = {_barSizeHP.x * _lastHPValue, _barSizeHPWhite.y};
    }
};

#endif