#ifndef BRIDGE_PART_SPRITE_H
#define BRIDGE_PART_SPRITE_H

#include "../GameObject.h"
#include "../../Observer/IObserver.h"
#include "raymath.h"

class BridgePartSprite : public GameObject, public IObserver
{
private:
    Rectangle _dist, _source;
    Texture2D _sprite;

    Color _color = CLITERAL(Color){255, 255, 255, 0};

    bool _canDraw = false;
    float _alpha = 0;

public:
    void virtual Start() override
    {
        _sprite = LoadTexture("resources/tilemap/tileset.png");
        Position = {656, 832};
        _source = {Position.x, Position.y, 24, 8};
        _dist = {16, 32, 24, 8};

        _color.a = _alpha;
    }

    void virtual Update(float dt) override
    {
        if (!_canDraw)
            return;

        _alpha = Clamp(_alpha - 5, 0, 255);
        _color.a = _alpha;
    }

    void virtual Draw() override
    {
        if (_canDraw)
            DrawTexturePro(_sprite, _dist, _source, {0, 0}, 1.0f, WHITE);

        DrawRectanglePro(_source, {0, 0}, 1.0f, _color);
    }

    void virtual Notify() override
    {
        _canDraw = true;
        _alpha = 255;
    }
};

#endif // BRIDGE_PART_SPRITE_H