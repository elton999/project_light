#include "LightCharger.h"
#include "GameObject.h"
#include "raymath.h"
#include "../Colors.h"

void LightCharger::Start()
{
    ColorSquare = YELLOW;
}

void LightCharger::Update(float dt)
{
    if (CheckPlayerOverlap())
        ChargerPlayerLight(dt);
}

void LightCharger::Draw()
{
    DrawCircle(Position.x, Position.y, Radius, ColorSquare);
}

bool LightCharger::CheckPlayerOverlap()
{
    Rectangle playerRec{player->Position.x, player->Position.y, player->Size.x, player->Size.y};
    return CheckCollisionCircleRec(Position, Radius, playerRec);
}

void LightCharger::ChargerPlayerLight(float dt)
{
    player->LightPower = Clamp(player->LightPower + ChargeSpeed * dt, 0, 1.0f);
}