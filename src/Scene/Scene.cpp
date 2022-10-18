#include "Scene.h"
#include "raymath.h"

void Scene::updateLayer(std::list<GameObject *> layer, float dt)
{
    std::list<GameObject *>::iterator iterator = layer.begin();
    while (iterator != layer.end())
    {
        (*iterator)->Update(dt);
        ++iterator;
    }
}

void Scene::drawLayer(std::list<GameObject *> layer)
{
    std::list<GameObject *>::iterator iterator = layer.begin();
    while (iterator != layer.end())
    {
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

void Scene::drawEnemies()
{
    std::list<Enemy *>::iterator iterator = _enemies.begin();
    while (iterator != _enemies.end())
    {
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
    Freezing->Update(dt);
    if (Freezing->IsFreezing())
        return;

    updateLayer(_ui, dt);
    updateLayer(_backgrounds, dt);
    _player->Update(dt);
    updateEnemies(dt);

    updateLayer(_foregrounds, dt);
    updateHitBoxes();

    CameraUpdate();

    Shake->Update(dt);
}

void Scene::Draw()
{
    drawLayer(_backgrounds);
    _player->Draw();
    drawEnemies();

    drawLayer(_foregrounds);
}

void Scene::DrawUI() { drawLayer(_ui); }

void Scene::CameraUpdate()
{
    Camera->target = {
        std::truncf(_player->Position.x),
        std::truncf(_player->Position.y)};
    Camera->offset = Vector2Scale(Size, 0.5f);
    Camera->rotation = 0;
    Camera->zoom = 1.0f;
}

Rectangle Scene::GetCameraRec()
{
    return {
        Camera->target.x - Size.x / 2.0f,
        Camera->target.y - Size.y / 2.0f,
        Size.x,
        Size.y};
}

void Scene::AddForeground(GameObject *foreground)
{
    _foregrounds.push_back(foreground);
    foreground->SetScene(this);
    foreground->Start();
}

void Scene::AddPlayer(Player *player)
{
    _player = player;
    player->SetScene(this);
    player->Start();
}

void Scene::AddEnemy(Enemy *enemy)
{
    _enemies.push_back(enemy);
    enemy->SetScene(this);
    enemy->Start();
}

void Scene::AddBackground(GameObject *background)
{
    _backgrounds.push_back(background);
    background->SetScene(this);
    background->Start();
}

void Scene::AddUI(GameObject *ui)
{
    _ui.push_back(ui);
    ui->SetScene(this);
    ui->Start();
}

void Scene::AddHitBox(HitBox *hitbox) { _hitBoxes.push_back(hitbox); }

void Scene::AddSolid(Solid *solid) { _solids.push_back(solid); }