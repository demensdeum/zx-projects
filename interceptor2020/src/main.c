#pragma output REGISTER_SP = 0xD000

#include <z80.h>
#include <arch/zx.h>
#include <arch/zx/sp1.h>
#include <sound.h>

#include <malloc.h>

#include "debug/beep.h"
#include "resources/resources.h"
#include "syntaxExtensions/syntaxExtensions.h"
#include "engine/engine.h"
#include "stateControllers/stateControllers.h"

int main()
{
    Renderer *renderer = new(Renderer);
    Renderer_initialize(renderer);
    
    InGameStateController *inGameStateController = new(InGameStateController);
    InGameStateController_initialize(inGameStateController, renderer);
  
    TitleScreenStateController *titleScreenStateController = new(TitleScreenStateController);
    TitleScreenStateController_initiailize(titleScreenStateController, inGameStateController->stateController, renderer);
    
    GameOverStateController *gameOverStateController = new(GameOverStateController);
    GameOverStateController_initiailize(gameOverStateController, inGameStateController->stateController, renderer);
    inGameStateController->gameOverStateController = gameOverStateController->stateController;
    
    StateMachine *stateMachine = new(StateMachine);
    StateMachine_initialize(stateMachine);
    StateMachine_startWithController(stateMachine, titleScreenStateController->stateController);
    
    while (stateMachine->isRunning) {
        StateMachine_step(stateMachine);
    }
  
  return 0;
}
