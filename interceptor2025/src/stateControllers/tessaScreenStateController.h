#include "tessa.h"

struct TitleScreenStateControllerStruct {
    StateController *stateController;
};
typedef struct TitleScreenStateControllerStruct TitleScreenStateController;

void TitleScreenStateController_stepUncasted(void *stateControllerSubclass);
void TitleScreenStateController_step(TitleScreenStateController *titleScreenStateController);

void TitleScreenStateController_initiailize(TitleScreenStateController *titleScreenStateController) {

    StateController *stateController = new(StateController);
    stateController->subclassInstance = titleScreenStateController;
    stateController->subclassStepFunction = &TitleScreenStateController_stepUncasted;
    titleScreenStateController->stateController = stateController;

}

void TitleScreenStateController_stepUncasted(void *stateControllerSubclass) {
    TitleScreenStateController *titleScreenStateController = (TitleScreenStateController *)stateControllerSubclass;
    TitleScreenStateController_step(titleScreenStateController);
}

void TitleScreenStateController_step(TitleScreenStateController *titleScreenStateController) {
    unsigned char i;
    unsigned char *pt = tiles;

    for (i = 0; i < TILES_LEN; i++, pt += 8)
        sp1_TileEntry(TILES_BASE + i, pt);

    struct sp1_pss ps0;

    ps0.bounds    = &full_screen;
    ps0.flags     = SP1_PSSFLAG_INVALIDATE;
    ps0.visit     = 0;

    sp1_SetPrintPos(&ps0, 0, 0);
    sp1_PrintString(&ps0, ptiles);

    sp1_UpdateNow();
}
