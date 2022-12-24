#ifndef WALL_H
#define WALL_H

#include "raylib.h"
#include "GameObject.h"
#include "../Scene/Solid.h"
#include "../Observer/IObserver.h"

class Wall : public GameObject, public IObserver
{
private:
    Texture2D _sprite;
    int _offsetBlock = 16;
    int _numOfBlocks = 6;
    bool _isVisible = true;

public:
    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;

    void virtual Notify() override { _isVisible = false; }
};

#endif // WALL_H