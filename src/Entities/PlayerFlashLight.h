#ifndef PLAYER_FLASH_LIGHT_H
#define PLAYER_FLASH_LIGHT_H

#include "raylib.h"
#include "raymath.h"
#include "../Colors.h"
#include "GameObject.h"

class Player;

class PlayerFlashLight : public GameObject
{
private:
    int LightSegment{5};
    float LightDT{0};
    Player *_player;

public:
    bool LightOn{false};
    float LightAngle{0};
    float LightAngleLength{50.0f};
    float LightDistance{150.0f};
    float LightPower{1.0f};

    bool IsLightOn() { return LightOn && LightPower > 0; }
    bool IsPointInLight(Vector2 position);

    Vector2 GetLightDirection() { return {sin(LightAngle * DEG2RAD), cos(LightAngle * DEG2RAD)}; }

    void SetPlayer(Player *player) { _player = player; }

    void virtual Update(float dt) override;
    void virtual Draw() override;
};

#endif // PLAYER_FLASH_LIGHT_H