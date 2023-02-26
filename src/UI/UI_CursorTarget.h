#ifndef UI_CURSOR_TARGET
#define UI_CURSOR_TARGET

#include "../Entities/GameObject.h"

class UI_CursorTarget : public GameObject
{

private:
    Texture2D *_sprite{};
    Rectangle _source{0, 0, 9, 9};
    Rectangle _dest{36, 20, 9, 9};

public:
    UI_CursorTarget(Texture2D *sprite) { _sprite = sprite; }

    virtual void Update(float dt) override;
    virtual void Draw() override;
};

#endif // UI_CURSOR_TARGET