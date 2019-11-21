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
    beep();
    in_wait_key();    
}
