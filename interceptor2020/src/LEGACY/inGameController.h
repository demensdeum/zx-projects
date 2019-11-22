 struct InGameControllerStruct {
     GameObject *interceptor;
     GameObject *bullet;
     InputController *inputController;
     SceneController *sceneController;
     Renderer *renderer;
     ScrollingTilesController *scrollingTilesController;
     EnemiesController *enemiesController;
     StateController *stateController;
     StateController *gameOverStateController;
     unsigned char steps;
};
typedef struct InGameControllerStruct InGameController;

void InGameController_step(InGameController *inGameController);
void InGameController_stepUncasted(void *stateControllerSubclass);

static InGameController *inGameController;

void InGameController_initialize(InGameController *inGameController) {
  GameObject *interceptor = GameObjectFactory_static_makeGameObject(8, 8);
  GameObject *bullet = GameObjectFactory_static_makeGameObject(8, 8);
    inGameController->interceptor = interceptor;
    inGameController->bullet = bullet;
  
  InputController *inputController = new(InputController);
  InputController_initialize(inputController);  
  inGameController->inputController = inputController;
  
  SceneController *sceneController = new(SceneController);
  SceneController_initialize(sceneController, interceptor, bullet, inputController);
  inGameController->sceneController = sceneController;
  
  Renderer *renderer = new(Renderer);
  Renderer_initialize(renderer, &full_screen);
  Renderer_addObject(renderer, interceptor);
  Renderer_addObject(renderer, bullet);
  inGameController->renderer = renderer;
  
  ScrollingTilesController *scrollingTilesController = new(ScrollingTilesController);
  ScrollingTilesController_initialize(scrollingTilesController, renderer);
  inGameController->scrollingTilesController = scrollingTilesController;
  
  EnemiesController *enemiesController = new(EnemiesController);
  EnemiesController_initialize(enemiesController, renderer);
  inGameController->enemiesController = enemiesController;
  
  StateController *stateController = new(StateController);
  stateController->subclassInstance = inGameController;
  stateController->subclassStepFunction = &InGameController_stepUncasted;
  stateController->nextStateController = nullptr;
  inGameController->stateController = stateController;
  
  inGameController->steps = 0;
}

void InGameController_deinitialize(InGameController *inGameController) {
     free(inGameController->interceptor);
     free(inGameController->bullet);
     free(inGameController->inputController);
     free(inGameController->sceneController);
     free(inGameController->renderer);
     free(inGameController->scrollingTilesController);
     free(inGameController->enemiesController);
}

void InGameController_reset(InGameController *inGameController) {
    inGameController->stateController->nextStateController = nullptr;
    inGameController->steps = 0;    
}

void InGameController_showGameOver(InGameController *inGameController) {
    StateController *gameOverStateController = inGameController->gameOverStateController;
    inGameController->stateController->nextStateController = gameOverStateController;    
}

void InGameController_stepUncasted(void *stateControllerSubclass) {
    InGameController *inGameController = (InGameController *)stateControllerSubclass;
    InGameController_step(inGameController);
}

void InGameController_step(InGameController *inGameController) {
    InputController_step(inGameController->inputController);
    SceneController_step(inGameController->sceneController);
    ScrollingTilesController_step(inGameController->scrollingTilesController);
    EnemiesController_step(inGameController->enemiesController);
    
    Renderer_render(inGameController->renderer);

    sp1_UpdateNow();
    
    if (inGameController->steps < 10) {
        inGameController->steps++;
        inGameController->stateController->nextStateController = nullptr;
    }
    else {
        InGameController_reset(inGameController);
        InGameController_showGameOver(inGameController);
    }
}
