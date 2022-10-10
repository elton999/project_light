#ifndef BRIDGE_PART_COLLECTABLE
#define BRIDGE_PART_COLLECTABLE

#include "Collectable.h"
#include "raylib.h"

class BridgePartCollectable : public Collectable
{
public:
    BridgePartCollectable(Texture2D *sprite) : Collectable(sprite, {}) {}

    void virtual Start() override;
    void virtual Update(float dt) override;
};

#endif // BRIDGE_PART_COLLECTABLE