struct InGameStateControllerStruct {
     StateController *stateController;
     StateController *gameOverStateController;
};
typedef struct InGameStateControllerStruct InGameStateController;

void InGameStateController_stepUncasted(void *stateControllerSubclass);
void InGameStateController_step(InGameStateController *inGameStateController);

void InGameStateController_initialize(InGameStateController *inGameStateController) {
  StateController *stateController = new(StateController);
  stateController->subclassInstance = inGameStateController;
  stateController->subclassStepFunction = &InGameStateController_stepUncasted;
  stateController->nextStateController = nullptr;
  inGameStateController->stateController = stateController;
  inGameStateController->gameOverStateController = nullptr;
}

void InGameStateController_stepUncasted(void *stateControllerSubclass) {
    InGameStateController *inGameStateController = (InGameStateController *)stateControllerSubclass;
    InGameStateController_step(inGameStateController);
}

void InGameStateController_step(InGameStateController *inGameStateController) {
    unsigned char i;
    unsigned char *pt = tessa_tiles;

    for (i = 0; i < TESSA_TILES_LEN; i++, pt += 8) {
        sp1_TileEntry(TESSA_TILES_BASE + i, pt);    
    }
    
     struct sp1_pss ps0;
     
   ps0.bounds    = &Renderer_fullScreenRect;
   ps0.flags     = SP1_PSSFLAG_INVALIDATE;
   ps0.visit     = 0;
     
     sp1_SetPrintPos(&ps0, 0, 0);
     sp1_PrintString(&ps0, tessa_ptiles);
    
    sp1_UpdateNow();
    
    inGameStateController->stateController->nextStateController = inGameStateController->gameOverStateController;
}
