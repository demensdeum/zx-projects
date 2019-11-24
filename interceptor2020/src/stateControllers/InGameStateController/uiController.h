struct UIControllerStruct {
    unsigned int previousScore;
    char previousShipHealth;    
    Renderer *renderer;
    char textBuffer[100];
};
typedef struct UIControllerStruct UIController;

void UIController_initialize(UIController *uiController, Renderer *renderer) {
    uiController->previousScore = 35715;
    uiController->previousShipHealth = 69;
    uiController->renderer = renderer;
}

void UIController_step(UIController *uiController, unsigned int score, char shipHealth) {
    unsigned int previousScore = uiController->previousScore;
    unsigned int previousShipHealth = uiController->previousShipHealth;
    if (previousScore == score && previousShipHealth == shipHealth) {
        return;
    }

    char *textBuffer = uiController->textBuffer;
    sprintf(textBuffer, "\x14\x46Money:%d$ Ship:%-3d", score, shipHealth);

    Renderer *renderer = uiController->renderer;
    Renderer_renderText(renderer, textBuffer, 0, 23);

    uiController->previousScore = score;
    uiController->previousShipHealth = shipHealth;
}
