struct GameOverStateControllerStruct {
     StateController *stateController;
     Renderer *renderer;
};
typedef struct GameOverStateControllerStruct GameOverStateController;

void GameOverStateController_stepUncasted(void *stateControllerSubclass);
void GameOverStateController_step(GameOverStateController *gameOverStateController);

void GameOverStateController_initiailize(GameOverStateController *gameOverStateController, StateController *nextStateController, Renderer *renderer) {
  StateController *stateController = new(StateController);
  stateController->subclassInstance = gameOverStateController;
  stateController->subclassStepFunction = &GameOverStateController_stepUncasted;
  stateController->nextStateController = nextStateController;
  gameOverStateController->stateController = stateController;
  gameOverStateController->renderer = renderer;
}

void GameOverStateController_stepUncasted(void *stateControllerSubclass) {
    GameOverStateController *gameOverStateController = (GameOverStateController *)stateControllerSubclass;
    GameOverStateController_step(gameOverStateController);
}

void GameOverStateController_step(GameOverStateController *gameOverStateController) {
    FullscreenImage *gameOverImage = new(FullscreenImage);
    FullscreenImage_initialize(gameOverImage, 
                               GAME_OVER_IMAGE_TILES_BASE, 
                               GAME_OVER_IMAGE_TILES_LEN, 
                               gameOverImage_tiles, 
                               gameOverImage_ptiles);    
    
    Renderer *renderer = gameOverStateController->renderer;
    Renderer_renderFullscreenImage(renderer, gameOverImage);
    Renderer_updateScreen(renderer);
    
    in_wait_key();
    
    delete(gameOverImage);
    Renderer_clearScreen(renderer);  
}
