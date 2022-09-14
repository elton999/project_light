#include "LightCharger.h"
#include "../Scene/Scene.h"
#include "raymath.h"
#include "../Colors.h"

void LightCharger::Start()
{
    ColorSquare = YELLOW;
    Position = {-100, 0};
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
    Rectangle playerRec{
        _scene->GetPlayer()->Position.x,
        _scene->GetPlayer()->Position.y,
        _scene->GetPlayer()->Size.x,
        _scene->GetPlayer()->Size.y};
    return CheckCollisionCircleRec(Position, Radius, playerRec);
}

void LightCharger::ChargerPlayerLight(float dt)
{
    _scene->GetPlayer()->LightPower = Clamp(_scene->GetPlayer()->LightPower + ChargeSpeed * dt, 0, 1.0f);
}