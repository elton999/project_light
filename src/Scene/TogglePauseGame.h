#ifndef TOGGLE_PAUSE_GAME
#define TOGGLE_PAUSE_GAME

#include "../Observer/IObserver.h"

class TogglePauseGame : public IObserver
{
private:
    bool paused = false;

public:
    void virtual Notify() override { paused = !paused; }
    bool IsPaused() { return paused; }
};

#endif