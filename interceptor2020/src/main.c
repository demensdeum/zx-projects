#pragma output REGISTER_SP = 0xD000

#include <malloc.h>

#include <z80.h>
#include <arch/zx.h>
#include <arch/zx/sp1.h>

#include "new.h"
#include "bool.h"

#include "resources.h"

#include "sprite.h"
#include "gameObject.h"
#include "inputController.h"
#include "sceneController.h"
#include "gameObjectFactory.h"
#include "renderer.h"
#include "scrollingTilesController.h"
#include "enemiesController.h"
#include "stateControllerIdentifier.h"
#include "stateController.h"
#include "stateMachine.h"
#include "inGameController.h"

int main()
{
  zx_border(INK_BLACK);

  sp1_Initialize( SP1_IFLAG_MAKE_ROTTBL | SP1_IFLAG_OVERWRITE_TILES | SP1_IFLAG_OVERWRITE_DFILE,
                  INK_BLACK | PAPER_WHITE,
                  ' ' );
  sp1_Invalidate(&full_screen);
 
  InGameController *inGameController = new(InGameController);
  InGameController_initialize(inGameController);
  
  while(inGameController->nextStateControllerIdentifier == none)
  {
        InGameController_step(inGameController);
  }
  
  return 0;
}
