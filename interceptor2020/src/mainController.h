struct MainControllerStruct {
     GameOverStateController *gameOverStateController;
};
typedef struct MainControllerStruct MainController;

void MainController_initialize(MainController *mainController, GameOverStateController *gameOverStateController) {
    mainController->gameOverStateController = gameOverStateController;
}

void MainController_inGameStateControllerDidFinishWithScoreFunction(MainController *mainController, InGameStateController *inGameStateController, unsigned int score) {
    GameOverStateController *gameOverStateController = mainController->gameOverStateController;
    gameOverStateController->score = score;
    inGameStateController->stateController->nextStateController = gameOverStateController->stateController;
}
