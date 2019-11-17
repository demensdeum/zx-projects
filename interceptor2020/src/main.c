#pragma output REGISTER_SP = 0xD000

#include <z80.h>
#include <arch/zx.h>
#include <arch/zx/sp1.h>

#include "bool.h"

#include "gameObject.h"
#include "inputController.h"

extern unsigned char bubble_col1[];
extern unsigned char bubble_col2[];

struct sp1_Rect full_screen = {0, 0, 32, 24};

void initialiseColour(unsigned int count, struct sp1_cs *c)
{
  (void)count;    /* Suppress compiler warning about unused parameter */

  c->attr_mask = SP1_AMASK_INK;
  c->attr      = INK_BLUE;
}

int main()
{
  struct sp1_ss  *bubble_sprite;

  InputController inputController;
  inputController_initialize(&inputController);
  
  GameObject gameObject;
  GameObject_initialize(&gameObject, 8, 8);

  zx_border(INK_BLACK);

  sp1_Initialize( SP1_IFLAG_MAKE_ROTTBL | SP1_IFLAG_OVERWRITE_TILES | SP1_IFLAG_OVERWRITE_DFILE,
                  INK_BLACK | PAPER_WHITE,
                  ' ' );
  sp1_Invalidate(&full_screen);
 
  bubble_sprite = sp1_CreateSpr(SP1_DRAW_MASK2LB, SP1_TYPE_2BYTE, 3, 0, 0);
  sp1_AddColSpr(bubble_sprite, SP1_DRAW_MASK2,    SP1_TYPE_2BYTE, bubble_col2-bubble_col1, 0);
  sp1_AddColSpr(bubble_sprite, SP1_DRAW_MASK2RB,  SP1_TYPE_2BYTE, 0, 0);
  
  sp1_IterateSprChar(bubble_sprite, initialiseColour);  
  
  while(true)
  {      
    inputController_step(&inputController);
    if ((&inputController)->upButtonPressed) {
        (&gameObject)->y--;
    }
    else if ((&inputController)->downButtonPressed) {
        (&gameObject)->y++;
    }
      
    sp1_MoveSprPix(bubble_sprite, &full_screen, bubble_col1, (&gameObject)->x, (&gameObject)->y);

    //z80_delay_ms(1);
    sp1_UpdateNow();
    
  }
}
