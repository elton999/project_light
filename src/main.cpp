#include "raylib.h"
#include "Entities/GameObject.h"
#include "Entities/Player.h"
#include "Entities/Weapon.h"
#include "Entities/Enemy.h"

//#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
#include <unistd.h>
#include <emscripten/emscripten.h>
#endif

int screenWidth = 400;
int screenHeight = 400;

Player *player = new Player();
Weapon *weapon = new Weapon();
GameObject *entities[3];

void StartEntities(void);
void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Project Light Alpha");

    weapon->SetPlayer(*player);

    entities[0] = player;
    entities[1] = new Enemy(*player);
    entities[2] = weapon;

    StartEntities();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
        UpdateDrawFrame();
#endif

    CloseWindow();

    return 0;
}

void StartEntities(void)
{
    for (auto entity : entities)
        entity->Start();
}

void UpdateDrawFrame(void)
{
    BeginDrawing();

    ClearBackground(WHITE);

    float deltaTime = GetFrameTime();
    for (auto entity : entities)
    {
        entity->Update(deltaTime);
        entity->Draw();
    }

    EndDrawing();
}