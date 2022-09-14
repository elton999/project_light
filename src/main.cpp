#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "TileMap.h"

#include "Scene/Scene.h"
#include "Entities/GameObject.h"
#include "Entities/Player.h"
#include "Entities/Weapon.h"
#include "Entities/Enemy.h"
#include "Entities/LightCharger.h"
#include "Entities/Ui.h"
#include "Entities/SpriteAnimation.h"

#include "Colors.h"

//#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
#include <unistd.h>
#include <emscripten/emscripten.h>
#endif

int screenWidth = 426;
int screenHeight = 240;

int windowScale = 2;

Camera2D camera = {};
tiles tilesData = ReadTileMap();
Scene scene = {};

Texture2D tileSprite;

RenderTexture backBuffer;

void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(screenWidth * windowScale, screenHeight * windowScale, "Project Light Alpha");

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    backBuffer = LoadRenderTexture(screenWidth, screenHeight);

    tileSprite = LoadTexture("resources/tilemap/tileset.png");

    Vector2 cameraSize = {(float)screenWidth, (float)screenHeight};

    camera = {0};

    TraceLog(LOG_INFO, "_________________player");
    Player player = {&tilesData};
    TraceLog(LOG_INFO, "player_________________");
    scene.AddPlayer(&player);
    scene.AddBackground(new LightCharger());
    scene.AddBackground(new Weapon());
    scene.AddEnemy(new Enemy(&tilesData, cameraSize));
    scene.AddUI(new Ui());

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

void UpdateDrawFrame(void)
{
    camera.target = scene.GetPlayer()->Position;
    camera.offset = {screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    // enemy->CameraPosition = Vector2Subtract(player->Position, camera.offset);

    // draw in sprite
    BeginTextureMode(backBuffer);
    ClearBackground(PURPLE);
    BeginMode2D(camera);

    DrawTileMap(tilesData, {scene.GetPlayer()->Position.x, scene.GetPlayer()->Position.y, (float)screenWidth, (float)screenHeight}, tileSprite);

    float deltaTime = GetFrameTime();

    scene.Update(deltaTime);

    EndMode2D();

    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);

    Vector2 sizesScreen = Vector2Divide({(float)GetScreenWidth(), (float)GetScreenHeight()}, {(float)screenWidth, (float)screenHeight});
    sizesScreen = Vector2Scale({(float)screenWidth, (float)screenHeight}, sizesScreen.x > sizesScreen.y ? sizesScreen.y : sizesScreen.x);
    Vector2 origin = {sizesScreen.x / 2.0f - GetScreenWidth() / 2.0f, sizesScreen.y / 2.0f - GetScreenHeight() / 2.0f};

    DrawTexturePro(backBuffer.texture, {0, 0, (float)screenWidth, -(float)screenHeight}, {0, 0, sizesScreen.x, sizesScreen.y}, origin, 0.0f, WHITE);
    EndDrawing();
}