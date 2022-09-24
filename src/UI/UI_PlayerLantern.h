#ifndef UI_PLAYER_LANTERN_H
#define UI_PLAYER_LANTERN_H

#include "raylib.h"
#include "../Entities/GameObject.h"

class UI_PlayerLantern : public GameObject
{
private:
    Rectangle _spriteOnSource{0, 0, 10, 10};
    Rectangle _spriteOffSource{10, 0, 10, 10};
    Rectangle _spriteDist{107, 18, 10, 10};

public:
    Texture2D Sprite;

    void virtual Start() override;
    void virtual Update(float dt) override {}
    void virtual Draw() override;
};

#endif