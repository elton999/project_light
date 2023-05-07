#ifndef UI_PLAYER_BACKPACK_H
#define UI_PLAYER_BACKPACK_H

#include "../Entities/GameObject.h"
#include "../Entities/Player.h"
#include "../Observer/IObserver.h"

class UI_PlayerBackpack : public GameObject, public IObserver
{
private:
    Texture2D _sprite{};
    float _alpha{255};
    bool _isPlayingEffect{false};

public:
    Rectangle Dest{220, 12, 16, 16};

    virtual void Start() override;
    virtual void Update(float dt) override;
    virtual void Draw() override;
    virtual void Notify() override;
};

#endif // UI_PLAYER_BACKPACK_H