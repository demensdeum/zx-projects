#include "interceptorController.h"
#include "spaceMinesController.h"
#include "enemyController.h"
#include "scoreController.h"

struct InGameStateControllerStruct {
    bool isStarted;
    Renderer *renderer;
    StateController *stateController;
    InterceptorController *interceptorController;
    SpaceMinesController *spaceMinesController;
    EnemyController *enemyController;
    ScoreController *scoreController;
    unsigned int score;
    void *delegate;
    void (*inGameStateControllerDidFinishWithScoreFunction)(void *, void *, unsigned int);
};
typedef struct InGameStateControllerStruct InGameStateController;

void InGameStateController_stepUncasted(void *stateControllerSubclass);
void InGameStateController_step(InGameStateController *inGameStateController);

void InGameStateController_initialize(InGameStateController *inGameStateController, Renderer *renderer, void *delegate, void (*inGameStateControllerDidFinishWithScoreFunction)(void *, void *, unsigned int)) {
    StateController *stateController = new(StateController);
    stateController->subclassInstance = inGameStateController;
    stateController->subclassStepFunction = &InGameStateController_stepUncasted;
    stateController->nextStateController = nullptr;
    inGameStateController->stateController = stateController;
    inGameStateController->renderer = renderer;
    inGameStateController->isStarted = false;
    inGameStateController->score = 0;
    inGameStateController->delegate = delegate;
    inGameStateController->inGameStateControllerDidFinishWithScoreFunction = inGameStateControllerDidFinishWithScoreFunction;
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

    ScoreController *scoreController = new(ScoreController);
    ScoreController_initialize(scoreController, renderer);
    inGameStateController->scoreController = scoreController;
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

    delete(inGameStateController->scoreController);
}

void InGameStateController_initializeControllersIfNeeded(InGameStateController *inGameStateController) {
    if (inGameStateController->isStarted == false) {
        InGameStateController_initializeControllers(inGameStateController);
    }
}

void InGameStateController_showGameOver(InGameStateController *inGameStateController) {
    inGameStateController->inGameStateControllerDidFinishWithScoreFunction(inGameStateController->delegate, inGameStateController, inGameStateController->score);
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
    ScoreController_step(inGameStateController->scoreController, inGameStateController->score);

    Renderer_updateScreen(renderer);

#if INTERCEPTOR2020_STRESS_TEST == 1
    InGameStateController_showGameOver(inGameStateController);
#endif
}
