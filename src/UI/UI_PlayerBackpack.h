#ifndef UI_PLAYER_BACKPACK_H
#define UI_PLAYER_BACKPACK_H

#include "../Entities/GameObject.h"
#include "../Entities/Player.h"
#include "../Observer/IObserver.h"

class UI_PlayerBackpack : public GameObject, public IObserver
{
private:
    Texture2D _sprite{};
    float _alpha{0};
    bool _isPlayingEffect{false};
    const float _collectItemSizeMultiplier{50.0f};
    const float _collectItemSpeedEfx{200.0f};
    const int _maxAlphaValue{255};

public:
    Rectangle Dest{220, 12, 16, 16};

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Notify() override;

    void DrawCollectEffect();
};

#endif // UI_PLAYER_BACKPACK_H