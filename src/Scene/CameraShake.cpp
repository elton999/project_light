#include "CameraShake.h"
#include "Scene.h"

#include "raylib.h"
#include "raymath.h"

#include <cstdlib>

void CameraShake::Update(float dt)
{
    timerShake -= dt;
    if (timerShake <= 0)
        return;

    int x = rand() % (SHAKE_MAGINTUDE * 2) - SHAKE_MAGINTUDE;
    int y = rand() % (SHAKE_MAGINTUDE * 2) - SHAKE_MAGINTUDE;

    _scene->Camera->target = Vector2Add(_scene->Camera->target, {(float)x, (float)y});
}

void CameraShake::Notify() { timerShake = TIME_OF_SHAKE; }