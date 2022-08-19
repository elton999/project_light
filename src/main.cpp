#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

#include "Entities/GameObject.h"
#include "Entities/Player.h"
#include "Entities/Weapon.h"
#include "Entities/Enemy.h"
#include "Entities/LightCharger.h"
#include "Entities/Ui.h"

#include "TileMap.h"

#include "Colors.h"

//#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
#include <unistd.h>
#include <emscripten/emscripten.h>
#endif

int screenWidth = 426;
int screenHeight = 240;

int windowScale = 2;

Camera2D camera;

Player *player = new Player();
Enemy *enemy = new Enemy(*player);
Weapon *weapon = new Weapon();
Ui *ui = new Ui();

tiles tilesData;
Texture2D tileSprite;

RenderTexture backBuffer;

GameObject *entities[4];

void StartEntities(void);
void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(screenWidth * windowScale, screenHeight * windowScale, "Project Light Alpha");

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    backBuffer = LoadRenderTexture(screenWidth, screenHeight);

    tilesData = ReadTileMap();
    tileSprite = LoadTexture("resources/tilemap/tileset.png");

    weapon->SetPlayer(*player);
    weapon->SetEnemy(*enemy);
    LightCharger *light = new LightCharger();
    light->player = player;

    ui->Start();
    ui->SetPlayer(*player);

    camera = {0};

    entities[0] = light;
    entities[1] = player;
    entities[2] = enemy;
    entities[3] = weapon;

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
    ClearBackground(PURPLE);
    BeginMode2D(camera);

    DrawTileMap(tilesData, tileSprite);

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
    Vector2 sizesScreen = Vector2Divide({(float)GetScreenWidth(), (float)GetScreenHeight()}, {(float)screenWidth, (float)screenHeight});
    sizesScreen = Vector2Scale({(float)screenWidth, (float)screenHeight}, sizesScreen.x > sizesScreen.y ? sizesScreen.y : sizesScreen.x);
    Vector2 origin = {sizesScreen.x / 2.0f - GetScreenWidth() / 2.0f, sizesScreen.y / 2.0f - GetScreenHeight() / 2.0f};
    DrawTexturePro(backBuffer.texture, {0, 0, (float)screenWidth, -(float)screenHeight}, {0, 0, sizesScreen.x, sizesScreen.y}, origin, 0.0f, WHITE);
    EndDrawing();
}