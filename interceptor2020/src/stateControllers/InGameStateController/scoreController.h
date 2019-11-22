struct ScoreControllerStruct {
    unsigned int score;
    Renderer *renderer;
};
typedef struct ScoreControllerStruct ScoreController;

void ScoreController_initialize(ScoreController *scoreController, Renderer *renderer) {
    scoreController->score = 0;
    scoreController->renderer = renderer;
}

void ScoreController_step(ScoreController *scoreController) {
    Renderer *renderer = scoreController->renderer;
    Renderer_renderText(renderer, "\x14\x46Money: 0$", 0, 23);
}
