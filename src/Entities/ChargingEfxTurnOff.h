#ifndef CHARGING_EFX_TURN_OFF_H
#define CHARGING_EFX_TURN_OFF_H

#include "ChargingEfx.h"
#include "../Observer/IObserver.h"

class ChargingEfxTurnOff : public IObserver
{
private:
    ChargingEfx *_chargingEfx;

public:
    ChargingEfxTurnOff(ChargingEfx *chargingEfx) { _chargingEfx = chargingEfx; }
    virtual void Notify() override { _chargingEfx->SetActive(false); }
};

#endif