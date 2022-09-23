#include "ExplosionEfx.h"

void ExplosionEfx::Start()
{
    Sprite = LoadTexture("resources/efx/pop_efx.png");
    maxFrames = 8;
    frame = 7;
    Size = {32, 32};
    Origin = {16, 16};
    width = 32;
    height = 32;
}