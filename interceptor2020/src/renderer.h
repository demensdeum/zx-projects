#define RENDERER_MAX_OBJECTS 10

struct RendererStruct {
    unsigned char objectsCount;    
    GameObject *objects[RENDERER_MAX_OBJECTS];
  struct sp1_Rect *full_screen;
};
typedef struct RendererStruct Renderer;

void Renderer_initialize(Renderer *renderer, struct sp1_Rect *full_screen) {
    renderer->objectsCount = 0;
    renderer->full_screen = full_screen;
}

void Renderer_addObject(Renderer *renderer, GameObject *gameObject) {
    if (renderer->objectsCount >= RENDERER_MAX_OBJECTS) {
        return;
    }
    renderer->objects[renderer->objectsCount] = gameObject;
    renderer->objectsCount++;
}

void Renderer_render(Renderer *renderer) {
    struct sp1_Rect *full_screen = renderer->full_screen;
    for (unsigned char i = 0; i < renderer->objectsCount; i++) {
        GameObject *gameObject = renderer->objects[i];
        sp1_MoveSprPix(gameObject->gameObjectSprite, full_screen, bubble_col1, gameObject->x, gameObject->y);
    }
}
