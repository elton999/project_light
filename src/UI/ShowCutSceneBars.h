#ifndef SHOW_CUT_SCENE_BARS
#define SHOW_CUT_SCENE_BARS

#include "../Observer/IObserver.h"
#include "UI_CutSceneBars.h"

class ShowCutSceneBars : public IObserver
{

private:
    UI_CutSceneBars *_ui_sceneBars;

public:
    ShowCutSceneBars(UI_CutSceneBars *ui_sceneBars) { _ui_sceneBars = ui_sceneBars; }

    virtual void Notify() override { _ui_sceneBars->Show(); }
};

#endif