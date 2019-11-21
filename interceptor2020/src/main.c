#pragma output REGISTER_SP = 0xD000

#include <malloc.h>

#include <z80.h>
#include <arch/zx.h>
#include <arch/zx/sp1.h>

#include "bool.h"

extern unsigned char bubble_col1[];
extern unsigned char bubble_col2[];
struct sp1_Rect full_screen = {0, 0, 32, 24};

#include "sprite.h"
#include "gameObject.h"
#include "inputController.h"
#include "sceneController.h"
#include "gameObjectFactory.h"
#include "renderer.h"
#include "scrollingTilesController.h"
#include "enemiesController.h"
#include "inGameController.h"

int main()
{
  zx_border(INK_BLACK);

  sp1_Initialize( SP1_IFLAG_MAKE_ROTTBL | SP1_IFLAG_OVERWRITE_TILES | SP1_IFLAG_OVERWRITE_DFILE,
                  INK_BLACK | PAPER_WHITE,
                  ' ' );
  sp1_Invalidate(&full_screen);
 
  InGameController_initialize();
  
  return 0;
}
