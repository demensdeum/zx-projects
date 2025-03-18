struct TitleScreenStateControllerStruct {
    StateController *stateController;
    Renderer *renderer;
};
typedef struct TitleScreenStateControllerStruct TitleScreenStateController;

void TitleScreenStateController_stepUncasted(void *stateControllerSubclass);
void TitleScreenStateController_step(TitleScreenStateController *titleScreenStateController);

void TitleScreenStateController_initiailize(TitleScreenStateController *titleScreenStateController, StateController *nextStateController, Renderer *renderer) {
    StateController *stateController = new(StateController);
    stateController->subclassInstance = titleScreenStateController;
    stateController->subclassStepFunction = &TitleScreenStateController_stepUncasted;
    stateController->nextStateController = nextStateController;
    titleScreenStateController->stateController = stateController;
    titleScreenStateController->renderer = renderer;
}

void TitleScreenStateController_stepUncasted(void *stateControllerSubclass) {
    TitleScreenStateController *titleScreenStateController = (TitleScreenStateController *)stateControllerSubclass;
    TitleScreenStateController_step(titleScreenStateController);
}

void TitleScreenStateController_step(TitleScreenStateController *titleScreenStateController) {
    FullscreenImage *titleImage = new(FullscreenImage);
    FullscreenImage_initialize(titleImage,
                               INTERCEPTOR_LOGO_TILES_BASE,
                               INTERCEPTOR_LOGO_TILES_LEN,
                               interceptorLogo_tiles,
                               interceptorLogo_ptiles);

    Renderer *renderer = titleScreenStateController->renderer;
    Renderer_renderFullscreenImage(renderer, titleImage);
    
#if INTERCEPTOR2020_STRESS_TEST == 1
    Renderer_renderText(renderer, "\x14\x03Stress Test Mode", 0, 0);
#endif    
    
    Renderer_renderText(renderer, "\x14\x46Space Bounty Hunter", 7, 9);
    Renderer_renderText(renderer, "\x14\x47 Controls: W, S, [Space]", 4, 15);
    Renderer_renderText(renderer, "\x14\x47Press Any Key", 10, 13);
    Renderer_renderText(renderer, "\x14\x47 Created by Demens Deum", 4, 19);
    Renderer_renderText(renderer, "\x14\x47 demensdeum@gmail.com", 5, 20);
    Renderer_renderText(renderer, "\x14\x03 Yandex Retro Games Battle 2019", 0, 22);

    Renderer_updateScreen(renderer);
    in_wait_key();
    Renderer_clearScreen(renderer);

    delete(titleImage);
}
