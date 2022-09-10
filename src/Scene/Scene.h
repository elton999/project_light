#ifndef SCENE_H
#define SCENE_H

#include <list>
#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include "Entities/GameObject.h"

#include "HitBox.h"
#include "Solid.h"

class Scene
{
private:
    Player *_player;
    std::list<Enemy *> _enemies;
    std::list<GameObject *> _backgrounds;
    std::list<GameObject *> _ui;

    std::list<HitBox *> _hitBoxes;
    std::list<Solid *> _solids;

    void updateLayer(std::list<GameObject *> layer, float dt);
    void updateEnemies(float dt);
    void updateHitBoxes();

public:
    void Update(float dt);

    void AddPlayer(Player *player);
    void AddEnemy(Enemy *enemy);
    void AddBackground(GameObject *background);
    void AddUI(GameObject *ui);

    void AddHitBox(HitBox *hitBox);
    void AddSolid(Solid *solid);

    Player GetPlayer() { return *_player; }
};

#endif