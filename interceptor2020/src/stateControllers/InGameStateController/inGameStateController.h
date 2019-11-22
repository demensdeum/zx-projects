#include "interceptorController.h"
#include "spaceMinesController.h"
#include "enemyController.h"

struct InGameStateControllerStruct {
    bool isStarted;
    Renderer *renderer;
    StateController *stateController;
    StateController *gameOverStateController;
    InterceptorController *interceptorController;
    SpaceMinesController *spaceMinesController;
    EnemyController *enemyController;
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
    inGameStateController->isStarted = true;

    Renderer *renderer = inGameStateController->renderer;    
    Renderer_clearScreen(renderer);    
    
    InterceptorController *interceptorController = new(InterceptorController);
    InterceptorController_initialize(interceptorController, renderer);
    inGameStateController->interceptorController = interceptorController;
    
    SpaceMinesController *spaceMinesController = new(SpaceMinesController);
    SpaceMinesController_initialize(spaceMinesController, renderer);
    inGameStateController->spaceMinesController = spaceMinesController;
    
    EnemyController *enemyController = new(EnemyController);
    EnemyController_initialize(enemyController, renderer);
    inGameStateController->enemyController = enemyController;
    
}

void InGameStateController_deinitializeControllers(InGameStateController *inGameStateController) {
    inGameStateController->isStarted = false;
    
    Renderer *renderer = inGameStateController->renderer;    
    
    InterceptorController_deinitialize(inGameStateController->interceptorController, renderer);
    delete(inGameStateController->interceptorController);
    
    SpaceMinesController_deinitialize(inGameStateController->spaceMinesController, renderer);
    delete(inGameStateController->spaceMinesController);
    
    EnemyController_deinitialize(inGameStateController->enemyController, renderer);
    delete(inGameStateController->enemyController);    
}

void InGameStateController_initializeControllersIfNeeded(InGameStateController *inGameStateController) {
    if (inGameStateController->isStarted == false) {
        InGameStateController_initializeControllers(inGameStateController);
    }    
}

void InGameStateController_showGameOver(InGameStateController *inGameStateController) {
    inGameStateController->stateController->nextStateController = inGameStateController->gameOverStateController;
    InGameStateController_deinitializeControllers(inGameStateController);    
}

void InGameStateController_stepUncasted(void *stateControllerSubclass) {
    InGameStateController *inGameStateController = (InGameStateController *)stateControllerSubclass;
    InGameStateController_step(inGameStateController);
}

void InGameStateController_step(InGameStateController *inGameStateController) {
    InGameStateController_initializeControllersIfNeeded(inGameStateController);
    
    InterceptorController_step(inGameStateController->interceptorController);
    SpaceMinesController_step(inGameStateController->spaceMinesController);
    EnemyController_step(inGameStateController->enemyController);
    
    Renderer *renderer = inGameStateController->renderer;
    Renderer_renderGameObjects(renderer);
    Renderer_updateScreen(renderer); 
    
#if INTERCEPTOR2020_STRESS_TEST == 1
    InGameStateController_showGameOver(inGameStateController);
#endif
}
