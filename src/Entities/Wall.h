#ifndef WALL_H
#define WALL_H

#include "raylib.h"
#include "GameObject.h"
#include "../Scene/Solid.h"

class Wall : public GameObject
{
private:
    Texture2D _sprite;
    int _offsetBlock = 16;
    int _numOfBlocks = 6;

public:
    void virtual Start() override;
    void virtual Update(float dt) override;
    void virtual Draw() override;
};

#endif // WALL_H