#include "Scene.h"
#include "raymath.h"

void Scene::updateLayer(std::list<GameObject *> layer, float dt)
{
    for (GameObject *gameObject : layer)
        gameObject->Update(dt);
}

void Scene::drawLayer(std::list<GameObject *> layer)
{
    for (GameObject *gameObject : layer)
        gameObject->Draw();
}

void Scene::updateEnemies(float dt)
{
    for (Enemy *enemy : _enemies)
    {
        enemy->Update(dt);
    }
}

void Scene::drawEnemies()
{
    for (Enemy *enemy : _enemies)
        enemy->Draw();
}

void Scene::updateHitBoxes()
{
    for (HitBox *hitBox : _hitBoxes)
        hitBox->UpdateCheckCollision(*_player);
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
    Vector2 cameraTarget =
        {
            std::truncf(_player->Position.x),
            std::truncf(_player->Position.y)};

    Camera->target =
        {
            Lerp(Camera->target.x, cameraTarget.x, _cameraSpeed),
            Lerp(Camera->target.y, cameraTarget.y, _cameraSpeed)};

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