struct ScoreControllerStruct {
    unsigned int previousScore;
    Renderer *renderer;
};
typedef struct ScoreControllerStruct ScoreController;

void ScoreController_initialize(ScoreController *scoreController, Renderer *renderer) {
    scoreController->previousScore = 35715;
    scoreController->renderer = renderer;
}

void ScoreController_step(ScoreController *scoreController, unsigned int score) {
    unsigned int previousScore = scoreController->previousScore;
    if (previousScore == score) {
        return;
    }

    char textBuffer[30];
    sprintf(textBuffer, "\x14\x46Money: %d", score);

    Renderer *renderer = scoreController->renderer;
    Renderer_renderText(renderer, textBuffer, 0, 23);

    scoreController->previousScore = score;
}
