#pragma output REGISTER_SP = 0xD000

// C includes

#include <malloc.h>

// Spectrum specific

#include <z80.h>
#include <arch/zx.h>
#include <arch/zx/sp1.h>
#include <sound.h>

// C syntax extensions

#include "new.h"
#include "bool.h"
#include "beep.h"
#include "nullptr.h"

// Resources

#include "resources.h"

// Game includes

#include "sprite.h"
#include "gameObject.h"
#include "inputController.h"
#include "sceneController.h"
#include "gameObjectFactory.h"
#include "renderer.h"
#include "scrollingTilesController.h"
#include "enemiesController.h"
#include "stateController.h"
#include "stateMachine.h"
#include "titleScreenStateController.h"
#include "inGameController.h"
#include "gameOverStateController.h"

int main()
{
  zx_border(INK_BLACK);

  sp1_Initialize( SP1_IFLAG_MAKE_ROTTBL | SP1_IFLAG_OVERWRITE_TILES | SP1_IFLAG_OVERWRITE_DFILE,
                  INK_BLUE | PAPER_WHITE,
                  ' ' );
  sp1_Invalidate(&full_screen);
  
    InGameController *inGameController = new(InGameController);
    InGameController_initialize(inGameController);
  
    TitleScreenStateController *titleScreenStateController = new(TitleScreenStateController);
    TitleScreenStateController_initiailize(titleScreenStateController, inGameController->stateController);
    
    GameOverStateController *gameOverStateController = new(GameOverStateController);
    GameOverStateController_initiailize(gameOverStateController, inGameController->stateController);
    inGameController->gameOverStateController = gameOverStateController->stateController;
    
    StateMachine *stateMachine = new(StateMachine);
    StateMachine_initialize(stateMachine);
    StateMachine_startWithController(stateMachine, titleScreenStateController->stateController);
    
    while (stateMachine->isRunning) {
        StateMachine_step(stateMachine);
    }
  
  return 0;
}
