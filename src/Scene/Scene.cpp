#include "Scene.h"

void Scene::updateLayer(std::list<GameObject *> layer, float dt)
{
    std::list<GameObject *>::iterator iterator = layer.begin();
    while (iterator != layer.end())
    {
        (*iterator)->Update(dt);
        (*iterator)->Draw();
        ++iterator;
    }
}

void Scene::updateEnemies(float dt)
{
    std::list<Enemy *>::iterator iterator = _enemies.begin();
    while (iterator != _enemies.end())
    {
        (*iterator)->Update(dt);
        (*iterator)->Draw();
        ++iterator;
    }
}

void Scene::updateHitBoxes()
{
    std::list<HitBox *>::iterator iterator = _hitBoxes.begin();
    while (iterator != _hitBoxes.end())
    {
        (*iterator)->UpdateCheckCollision(*_player);
        ++iterator;
    }
}

void Scene::Update(float dt)
{
    _player->Update(dt);
    updateEnemies(dt);
    updateLayer(_backgrounds, dt);
    updateLayer(_ui, dt);
    updateHitBoxes();
}

void Scene::AddPlayer(Player *player)
{
    player->Start();
    _player = player;
}

void Scene::AddEnemy(Enemy *enemy)
{
    enemy->Start();
    _enemies.push_back(enemy);
}

void Scene::AddBackground(GameObject *background)
{
    background->Start();
    _backgrounds.push_back(background);
}

void Scene::AddUI(GameObject *ui)
{
    ui->Start();
    _ui.push_back(ui);
}

void Scene::AddHitBox(HitBox *hitbox) { _hitBoxes.push_back(hitbox); }

void Scene::AddSolid(Solid *solid) { _solids.push_back(solid); }