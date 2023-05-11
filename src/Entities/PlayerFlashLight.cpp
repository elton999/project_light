#include "PlayerFlashLight.h"
#include "Player.h"

bool PlayerFlashLight::IsPointInLight(Vector2 position)
{
    float distance = Vector2Distance(_player->Position, position);

    if (distance <= LightDistance && IsLightOn())
    {
        Vector2 pNormalized = Vector2Normalize(Vector2Subtract(position, _player->Position));
        return Vector2DotProduct(
                   GetLightDirection(),
                   pNormalized) >= cos(LightAngleLength / 2.0f * DEG2RAD);
    }
    return false;
}

void PlayerFlashLight::Update(float dt)
{
    LightDT += dt * 10;

    if (LightOn)
        LightPower = Clamp(LightPower - 0.1f * dt, 0, INFINITY);

    LightAngle = atan2f(GetScreenWidth() / 2.0f - GetMouseX(), GetScreenHeight() / 2.0f - GetMouseY()) * RAD2DEG;
    LightAngle += 180.0f;
}

void PlayerFlashLight::Draw()
{
    if (!IsLightOn() || _player->IsDead())
        return;

    float angleLength = LightAngleLength / 2.0f;
    Color lightColor = YELLOW;
    if (LightPower <= 0.3f)
        if ((int)LightDT % 4 < 2.f)
            lightColor = BLANK;

    DrawCircleSector(_player->Position, LightDistance, LightAngle + angleLength, LightAngle - angleLength, LightSegment, lightColor);
}