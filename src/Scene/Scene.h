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
    std::list<Player *> _player;
    std::list<Enemy *> _enemies;
    std::list<GameObject *> _backgrounds;

    std::list<HitBox *> _hitBoxs;
    std::list<Solid *> _solids;

public:
    void Update(float dt);
    void Draw();

    void AddPlayer(Player *player);
    void AddEnemy(Enemy *enemy);
    void AddBackground(GameObject *background);

    void AddHitBox(HitBox *hitBox);
    void AddSolid(Solid *solid);
};

#endif