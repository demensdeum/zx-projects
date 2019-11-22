struct InGameStateControllerStruct {
    bool isStarted;
    Renderer *renderer;
    StateController *stateController;
    StateController *gameOverStateController;
};
typedef struct InGameStateControllerStruct InGameStateController;

void InGameStateController_stepUncasted(void *stateControllerSubclass);
void InGameStateController_step(InGameStateController *inGameStateController);

void InGameStateController_initialize(InGameStateController *inGameStateController, Renderer *renderer) {
  StateController *stateController = new(StateController);
  stateController->subclassInstance = inGameStateController;
  stateController->subclassStepFunction = &InGameStateController_stepUncasted;
  stateController->nextStateController = nullptr;
  inGameStateController->stateController = stateController;
  inGameStateController->gameOverStateController = nullptr;
  inGameStateController->renderer = renderer;
  inGameStateController->isStarted = false;
}

void InGameStateController_initializeControllers(InGameStateController *inGameStateController) {
    beep();
    inGameStateController->isStarted = true;    
}

void InGameStateController_deinitializeControllers(InGameStateController *inGameStateController) {
    beep();
    inGameStateController->isStarted = false;
}

void InGameStateController_initializeControllersIfNeeded(InGameStateController *inGameStateController) {
    if (inGameStateController->isStarted == false) {
        InGameStateController_initializeControllers(inGameStateController);
    }    
}

void InGameStateController_stepUncasted(void *stateControllerSubclass) {
    InGameStateController *inGameStateController = (InGameStateController *)stateControllerSubclass;
    InGameStateController_step(inGameStateController);
}

void InGameStateController_step(InGameStateController *inGameStateController) {
    
    InGameStateController_initializeControllersIfNeeded(inGameStateController);
    
    Renderer *renderer = inGameStateController->renderer;
    Renderer_clearScreen(renderer);
    
    Renderer_updateScreen(renderer);
    
    inGameStateController->stateController->nextStateController = inGameStateController->gameOverStateController;
    InGameStateController_deinitializeControllers(inGameStateController);
}
