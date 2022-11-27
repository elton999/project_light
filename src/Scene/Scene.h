#ifndef SCENE_H
#define SCENE_H

#include <list>
#include "../Entities/Player.h"
#include "../Entities/Enemy.h"

#include "HitBox.h"
#include "Solid.h"

#include "FreezingFrame.h"
#include "CameraShake.h"

#include "raylib.h"

class GameObject;

class Scene
{
private:
    std::list<GameObject *> _foregrounds;
    std::list<Enemy *> _enemies;
    std::list<GameObject *> _backgrounds;
    std::list<GameObject *> _ui;

    std::list<HitBox *> _hitBoxes;
    std::list<Solid *> _solids;

    void updateLayer(std::list<GameObject *> layer, float dt);
    void drawLayer(std::list<GameObject *> layer);

    void updateEnemies(float dt);
    void drawEnemies();
    void updateHitBoxes();

public:
    Player *_player;
    FreezingFrame *Freezing = new FreezingFrame();
    CameraShake *Shake = new CameraShake(this);

    Camera2D *Camera;
    Vector2 Size;

    Rectangle GetCameraRec();

    void Update(float dt);
    void Draw();
    void DrawUI();
    void CameraUpdate();

    void AddForeground(GameObject *foreground);
    void AddPlayer(Player *player);
    void AddEnemy(Enemy *enemy);
    void AddBackground(GameObject *background);
    void AddUI(GameObject *ui);

    void AddHitBox(HitBox *hitBox);
    void AddSolid(Solid *solid);

    Player *GetPlayer() { return _player; }
    std::list<Enemy *> GetEnemies() { return _enemies; }
    std::list<Solid *> GetSolids() { return _solids; }
};

#endif