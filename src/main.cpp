#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "TileMap.h"

#include "Scene/Scene.h"
#include "Scene/Solid.h"

#include "Entities/GameObject.h"
#include "Entities/Player.h"
#include "Entities/Weapon.h"
#include "Entities/Enemy.h"
#include "Entities/AnimationEfx.h"
#include "Entities/ExplosionEfx.h"
#include "Entities/LightCharger.h"

#include "Entities/Collectables/KeyCollectable.h"
#include "Entities/Collectables/BridgePartCollectable.h"
#include "Entities/Collectables/BridgePartSprite.h"

#include "Scene/HitBoxs/BridgeGep.h"

#include "UI/UI_Bars.h"
#include "UI/UI_PlayerLantern.h"
#include "UI/UI_PlayerBackpack.h"

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

void SetAllEnemies(AnimationEfx *hitEfx, AnimationEfx *explosionEfx);
void SetAllLantern(Texture2D *sprite);

int main(void)
{
    InitWindow(screenWidth * windowScale, screenHeight * windowScale, "Project Light Alpha");

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    backBuffer = LoadRenderTexture(screenWidth, screenHeight);

    tileSprite = LoadTexture("resources/tilemap/tileset.png");
    Texture2D propsSprites = LoadTexture("resources/tilemap/propts.png");

    camera = {0};
    scene.Camera = &camera;
    scene.Size = {(float)screenWidth, (float)screenHeight};

    scene.AddPlayer(new Player(&tilesData));
    scene.AddForeground(new Weapon());
    SetAllLantern(&propsSprites);

    KeyCollectable *key = new KeyCollectable(&propsSprites);
    scene.AddBackground(key);
    scene.AddHitBox(key);

    BridgePartSprite *bridgePartSprite = new BridgePartSprite();
    scene.AddBackground(bridgePartSprite);

    Solid *bridgeWall = new Solid({656, 832, 24, 8});
    BridgeGep *bridgeGep = new BridgeGep({656, 824, 24, 8});
    bridgeGep->Add(new DisableSolid(bridgeWall));
    bridgeGep->Add(new DisableSolid(bridgeGep));
    bridgeGep->Add(bridgePartSprite);

    scene.AddBackground(bridgeGep);
    scene.AddHitBox(bridgeGep);
    scene.AddSolid(bridgeWall);

    BridgePartCollectable *bridgePart = new BridgePartCollectable(&propsSprites);
    scene.AddBackground(bridgePart);
    scene.AddHitBox(bridgePart);

    AnimationEfx *hitEfx = new AnimationEfx();
    ExplosionEfx *explosionEfx = new ExplosionEfx();
    scene.AddForeground(hitEfx);
    scene.AddForeground(explosionEfx);

    SetAllEnemies(hitEfx, explosionEfx);

    scene.AddUI(new UI_Bars());
    scene.AddUI(new UI_PlayerLantern());
    scene.AddUI(new UI_PlayerBackpack());

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
    float deltaTime = GetFrameTime();
    // draw in sprite
    BeginTextureMode(backBuffer);

    ClearBackground(PURPLE);
    BeginMode2D(*scene.Camera);

    DrawTileMap(tilesData, {scene.GetPlayer()->Position.x, scene.GetPlayer()->Position.y, (float)screenWidth, (float)screenHeight}, tileSprite);
    scene.Update(deltaTime);
    scene.Draw();

    EndMode2D();

    // HUD
    scene.DrawUI();

    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);

    Vector2 sizesScreen = Vector2Divide({(float)GetScreenWidth(), (float)GetScreenHeight()}, scene.Size);
    sizesScreen = Vector2Scale(scene.Size, sizesScreen.x > sizesScreen.y ? sizesScreen.y : sizesScreen.x);

    Vector2 origin = Vector2Subtract(
        Vector2Scale(sizesScreen, 0.5f),
        Vector2Scale({(float)GetScreenWidth(), (float)GetScreenHeight()}, 0.5f));
    Rectangle backBufferSource = {0, 0, (float)screenWidth, -(float)screenHeight};
    Rectangle backBufferDest = {0, 0, sizesScreen.x, sizesScreen.y};

    DrawTexturePro(backBuffer.texture, backBufferSource, backBufferDest, origin, 0.0f, WHITE);
    EndDrawing();
}

void SetAllLantern(Texture2D *sprite)
{
    Vector2 positions[1]{{88, 527}};
    for (auto pos : positions)
        scene.AddBackground(new LightCharger(pos, sprite));
}

void SetAllEnemies(AnimationEfx *hitEfx, AnimationEfx *explosionEfx)
{
    Vector2 positions[11]{
        {254, 563},
        {642, 701},
        {816, 614},
        {600, 528},
        {540, 439},
        {522, 435},
        {618, 321},
        {528, 166},
        {826, 192},
        {860, 152},
        {1105, 187},
    };

    Texture2D idle = LoadTexture("resources/troll.png");
    Texture2D walk = LoadTexture("resources/troll_walk.png");
    Texture2D freezing = LoadTexture("resources/troll_freezing.png");

    for (auto pos : positions)
    {
        Enemy *enemy = new Enemy(&tilesData, pos, &idle, &walk, &freezing);
        enemy->HitEfx = hitEfx;
        enemy->ExplosionEfx = explosionEfx;

        scene.AddEnemy(enemy);
    }
}