struct RendererStruct {
  GameObject *firstObject;
  GameObject *secondObject;
  struct sp1_Rect *full_screen;
};
typedef struct RendererStruct Renderer;

void Renderer_initialize(Renderer *renderer, GameObject *firstObject, GameObject *secondObject, struct sp1_Rect *full_screen) {
    renderer->full_screen = full_screen;
    renderer->firstObject = firstObject;
    renderer->secondObject = secondObject;
}

void Renderer_render(Renderer *renderer) {
    struct sp1_Rect *full_screen = renderer->full_screen;
    GameObject *firstObject = renderer->firstObject;
    GameObject *secondObject = renderer->secondObject;
    sp1_MoveSprPix(firstObject->gameObjectSprite, full_screen, bubble_col1, firstObject->x, firstObject->y);
    sp1_MoveSprPix(secondObject->gameObjectSprite, full_screen, bubble_col1, secondObject->x, secondObject->y);    
}
