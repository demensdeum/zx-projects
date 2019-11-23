#pragma output REGISTER_SP = 0xD000

#include <z80.h>
#include <arch/zx.h>
#include <arch/zx/sp1.h>
#include <sound.h>
#include <stdio.h>
#include <stdlib.h>

#include <malloc.h>

#define INTERCEPTOR2020_STRESS_TEST 0

#include "debug/beep.h"
#include "resources/resources.h"
#include "syntaxExtensions/syntaxExtensions.h"
#include "engine/engine.h"
#include "stateControllers/stateControllers.h"
#include "mainController.h"

int main()
{
    Renderer *renderer = new(Renderer);
    Renderer_initialize(renderer);

    MainController *mainController = new(MainController);

    InGameStateController *inGameStateController = new(InGameStateController);
    InGameStateController_initialize(inGameStateController, renderer, mainController, &MainController_inGameStateControllerDidFinishWithScoreFunction);

    TitleScreenStateController *titleScreenStateController = new(TitleScreenStateController);
    TitleScreenStateController_initiailize(titleScreenStateController, inGameStateController->stateController, renderer);

    GameOverStateController *gameOverStateController = new(GameOverStateController);
    GameOverStateController_initiailize(gameOverStateController, inGameStateController->stateController, renderer, 0);

    StateMachine *stateMachine = new(StateMachine);
    StateMachine_initialize(stateMachine);
    StateMachine_startWithController(stateMachine, titleScreenStateController->stateController);

    MainController_initialize(mainController, gameOverStateController);

    while (stateMachine->isRunning) {
        StateMachine_step(stateMachine);
    }

    return 0;
}
