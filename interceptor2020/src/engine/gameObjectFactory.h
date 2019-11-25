void initialiseColour(unsigned int count, struct sp1_cs *c)
{
    (void)count;

    c->attr_mask = SP1_AMASK_INK;
    c->attr      = INK_BLUE;
}

GameObject *GameObjectFactory_static_makeGameObject(unsigned char x, unsigned char y, unsigned char *col1, unsigned char *col2) {
    struct sp1_ss *bubble_sprite = sp1_CreateSpr(SP1_DRAW_MASK2LB, SP1_TYPE_2BYTE, 3, 0, 0);
    sp1_AddColSpr(bubble_sprite, SP1_DRAW_MASK2,    SP1_TYPE_2BYTE, col2-col1, 0);
    sp1_AddColSpr(bubble_sprite, SP1_DRAW_MASK2RB,  SP1_TYPE_2BYTE, 0, 0);
    sp1_IterateSprChar(bubble_sprite, initialiseColour);

    GameObject *gameObject = new(GameObject);
    GameObject_initialize(gameObject, bubble_sprite, col1, x, y);

    return gameObject;
}
