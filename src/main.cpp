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

int screenWidth = 426;
int screenHeight = 240;

Camera2D camera;

Player *player = new Player();
Enemy *enemy = new Enemy(*player);
Weapon *weapon = new Weapon();
Ui *ui = new Ui();

RenderTexture backBuffer;

GameObject *entities[3];

void StartEntities(void);
void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Project Light Alpha");

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    backBuffer = LoadRenderTexture(screenWidth, screenHeight);

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
    camera.offset = {screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    // draw in sprite
    BeginTextureMode(backBuffer);
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
    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);
    Vector2 sizesScreen = {(float)GetScreenWidth() / (float)screenWidth, (float)GetScreenHeight() / (float)screenHeight};
    sizesScreen = Vector2Scale({(float)screenWidth, (float)screenHeight}, sizesScreen.x > sizesScreen.y ? sizesScreen.y : sizesScreen.x);
    Vector2 origin = {sizesScreen.x / 2.0f - GetScreenWidth() / 2.0f, sizesScreen.y / 2.0f - GetScreenHeight() / 2.0f};
    DrawTexturePro(backBuffer.texture, {0, 0, (float)screenWidth, -(float)screenHeight}, {0, 0, sizesScreen.x, sizesScreen.y}, origin, 0.0f, WHITE);
    EndDrawing();
}