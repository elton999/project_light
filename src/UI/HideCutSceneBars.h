#ifndef HIDE_CUT_SCENE_BARS
#define HIDE_CUT_SCENE_BARS

#include "../Observer/IObserver.h"
#include "UI_CutSceneBars.h"

class HideCutScene : public IObserver
{
private:
    UI_CutSceneBars *_ui_sceneBars;

public:
    HideCutScene(UI_CutSceneBars *ui_sceneBars) { _ui_sceneBars = ui_sceneBars; }

    virtual void Notify() override { _ui_sceneBars->Hide(); }
};

#endif