#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

#include "Entities/GameObject.h"
#include "Entities/Player.h"
#include "Entities/Weapon.h"
#include "Entities/Enemy.h"
#include "Entities/Ui.h"

//#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
#include <unistd.h>
#include <emscripten/emscripten.h>
#endif

int screenWidth = 400;
int screenHeight = 400;

Camera2D camera;

Player *player = new Player();
Enemy *enemy = new Enemy(*player);
Weapon *weapon = new Weapon();
Ui *ui = new Ui();

GameObject *entities[3];

void StartEntities(void);
void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Project Light Alpha");

    weapon->SetPlayer(*player);
    weapon->SetEnemy(*enemy);

    ui->SetPlayer(*player);

    camera = {0};

    entities[0] = player;
    entities[1] = enemy;
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
    camera.target = player->Position;
    camera.offset = {200, 200};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    BeginDrawing();

    ClearBackground(WHITE);

    BeginMode2D(camera);

    rlPushMatrix();
    rlTranslatef(0, 25 * 50, 0);
    rlRotatef(90, 1, 0, 0);
    DrawGrid(100, 50);
    rlPopMatrix();

    float deltaTime = GetFrameTime();
    for (auto entity : entities)
    {
        entity->Update(deltaTime);
        entity->Draw();
    }
    EndMode2D();

    ui->Update(deltaTime);
    ui->Draw();

    EndDrawing();
}