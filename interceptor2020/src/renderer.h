struct RendererStruct {
  GameObject *firstObject;    
  struct sp1_Rect *full_screen;
};
typedef struct RendererStruct Renderer;

void Renderer_initialize(Renderer *renderer, GameObject *firstObject, struct sp1_Rect *full_screen) {
    renderer->full_screen = full_screen;
    renderer->firstObject = firstObject;
}

void Renderer_render(Renderer *renderer) {
    GameObject *gameObject = renderer->firstObject;
    struct sp1_Rect *full_screen = renderer->full_screen;
    sp1_MoveSprPix(gameObject->gameObjectSprite, full_screen, bubble_col1, gameObject->x, gameObject->y);
}
