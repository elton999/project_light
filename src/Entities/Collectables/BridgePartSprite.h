#ifndef BRIDGE_PART_SPRITE_H
#define BRIDGE_PART_SPRITE_H

#include "../GameObject.h"

class BridgePartSprite : public GameObject
{
private:
    Rectangle _dist, _source;
    Texture2D _sprite;

public:
    void virtual Start() override
    {
        _sprite = LoadTexture("resources/tilemap/tileset.png");
        Position = {656, 832};
        _dist = {Position.x, Position.y, 8, 24};
        _source = {16, 32, 8, 24};
    }

    void virtual Draw() override
    {
        DrawTexturePro(_sprite, _dist, _source, {0, 0}, 1.0f, WHITE);
    }
};

#endif // BRIDGE_PART_SPRITE_H