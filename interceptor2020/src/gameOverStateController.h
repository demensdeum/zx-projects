struct GameOverStateControllerStruct {
     StateController *stateController;
};
typedef struct GameOverStateControllerStruct GameOverStateController;

void GameOverStateController_stepUncasted(void *stateControllerSubclass);
void GameOverStateController_step(GameOverStateController *gameOverStateController);

void GameOverStateController_initiailize(GameOverStateController *gameOverStateController, StateController *nextStateController) {
  StateController *stateController = new(StateController);
  stateController->subclassInstance = gameOverStateController;
  stateController->subclassStepFunction = &GameOverStateController_stepUncasted;
  stateController->nextStateController = nextStateController;
  gameOverStateController->stateController = stateController;
}

void GameOverStateController_stepUncasted(void *stateControllerSubclass) {
    GameOverStateController *gameOverStateController = (GameOverStateController *)stateControllerSubclass;
    GameOverStateController_step(gameOverStateController);
}

void GameOverStateController_step(GameOverStateController *gameOverStateController) {

    unsigned char i;
    unsigned char *pt = gameOverImage_tiles;

    for (i = 0; i < GAME_OVER_IMAGE_TILES_LEN; i++, pt += 8) {
        sp1_TileEntry(GAME_OVER_IMAGE_TILES_BASE + i, pt);    
    }
    
	   	Renderer_clearScreen();   
    
     struct sp1_pss ps0;
     
   ps0.bounds    = &full_screen;
   ps0.flags     = SP1_PSSFLAG_INVALIDATE;
   ps0.attr_mask = 0;
   ps0.visit     = 0;
   
     sp1_SetPrintPos(&ps0, 0, 0);
     sp1_PrintString(&ps0, gameOverImage_ptiles);
     
    sp1_UpdateNow();
    
    beep();
    in_wait_key();  
    
    Renderer_clearScreen();  
}
