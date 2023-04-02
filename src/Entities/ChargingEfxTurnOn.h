#ifndef CHARGING_EFX_TURN_ON_H
#define CHARGING_EFX_TURN_ON_H

#include "../Observer/IObserver.h"
#include "ChargingEfx.h"

class ChargingEfxTurnOn : public IObserver
{
private:
    ChargingEfx *_chargingEfx;

public:
    ChargingEfxTurnOn(ChargingEfx *chargingEfx) { _chargingEfx = chargingEfx; }
    virtual void Notify() override { _chargingEfx->SetActive(true); }
};

#endif // CHARGING_EFX_TURN_ON_H