#ifndef UI_PLAYER_BACKPACK_H
#define UI_PLAYER_BACKPACK_H

#include "../Entities/GameObject.h"
#include "../Entities/Player.h"

class UI_PlayerBackpack : public GameObject
{
private:
    Texture2D _sprite{};

public:
    Rectangle Dest{220, 12, 16, 16};

    virtual void Start() override;
    virtual void Draw() override;
};

#endif // UI_PLAYER_BACKPACK_H