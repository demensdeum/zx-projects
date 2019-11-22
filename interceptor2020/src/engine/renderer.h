#define RENDERER_MAX_OBJECTS 32

struct RendererStruct {
    unsigned char objectsCount;    
    GameObject *objects[RENDERER_MAX_OBJECTS];
};
typedef struct RendererStruct Renderer;

struct sp1_Rect Renderer_fullScreenRect = {0, 0, 32, 24};

void Renderer_initialize(Renderer *renderer) {
    
    renderer->objectsCount = 0;
    
  zx_border(INK_BLACK);
  sp1_Initialize( SP1_IFLAG_MAKE_ROTTBL | SP1_IFLAG_OVERWRITE_TILES | SP1_IFLAG_OVERWRITE_DFILE,
                  INK_BLUE | PAPER_WHITE,
                  ' ' );
  sp1_Invalidate(&Renderer_fullScreenRect);
    
    
}

void Renderer_addObject(Renderer *renderer, GameObject *gameObject) {
    if (renderer->objectsCount >= RENDERER_MAX_OBJECTS) {
        return;
    }
    renderer->objects[renderer->objectsCount] = gameObject;
    renderer->objectsCount++;
}

void Renderer_render(Renderer *renderer) {
    for (unsigned char i = 0; i < renderer->objectsCount; i++) {
        GameObject *gameObject = renderer->objects[i];
        sp1_MoveSprPix(gameObject->gameObjectSprite, Renderer_fullScreenRect, bubble_col1, gameObject->x, gameObject->y);
    }
}

void Renderer_clearScreen(Renderer *renderer) {
    sp1_ClearRectInv(Renderer_fullScreenRect, BRIGHT | INK_BLACK | PAPER_BLACK, 32, SP1_RFLAG_TILE | SP1_RFLAG_COLOUR);      
}
