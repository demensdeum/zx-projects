struct GameOverStateControllerStruct {
    StateController *stateController;
    Renderer *renderer;
    unsigned int score;
};
typedef struct GameOverStateControllerStruct GameOverStateController;

void GameOverStateController_stepUncasted(void *stateControllerSubclass);
void GameOverStateController_step(GameOverStateController *gameOverStateController);

void GameOverStateController_initiailize(GameOverStateController *gameOverStateController, StateController *nextStateController, Renderer *renderer, unsigned int score) {
    StateController *stateController = new(StateController);
    stateController->subclassInstance = gameOverStateController;
    stateController->subclassStepFunction = &GameOverStateController_stepUncasted;
    stateController->nextStateController = nextStateController;
    gameOverStateController->stateController = stateController;
    gameOverStateController->renderer = renderer;
    gameOverStateController->score = score;
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
    Renderer_renderText(renderer, "\x14\x47Press Any Key", 10, 16);

    char textBuffer[30];
    sprintf(textBuffer, "\x14\x03Money: %d$", gameOverStateController->score);
    Renderer_renderText(renderer, textBuffer, 0, 23);

    Renderer_updateScreen(renderer);

#if INTERCEPTOR2020_STRESS_TEST == 0
    in_wait_nokey();
    in_wait_key();
#endif

    delete(gameOverImage);
    Renderer_clearScreen(renderer);
}
