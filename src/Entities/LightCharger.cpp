#include "LightCharger.h"
#include "PlayerFlashLight.h"
#include "../Scene/Scene.h"
#include "raymath.h"
#include "../Colors.h"

void LightCharger::Start() { ColorSquare = YELLOW; }

void LightCharger::Update(float dt)
{
    if (CheckPlayerOverlap())
    {
        OnStartCharging->Notify();
        ChargerPlayerLight(dt);
    }
    else
        OnStopCharging->Notify();

    TimerDt += dt;
    CurrentRadius = cosf(TimerDt * VelocityRadiusAnimation);
}

void LightCharger::Draw()
{
    DrawCircle(Position.x, Position.y, Radius + 5.0f + CurrentRadius, WHITE);
    DrawCircle(Position.x, Position.y, Radius + CurrentRadius, ColorSquare);

    Rectangle source{0, 0, 16, 16};
    Rectangle dest{Position.x, Position.y, 16, 16};
    DrawTexturePro(Sprite, source, dest, {8, 8}, 1.0f, WHITE);
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
    PlayerFlashLight *flashLight = _scene->GetPlayer()->FlashLight;
    flashLight->LightPower = Clamp(flashLight->LightPower + ChargeSpeed * dt, 0, 1.0f);
}