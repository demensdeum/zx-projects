#define SCROLLING_TILES_CONTROLLER_OBJECTS_ROW 4
#define SCROLLING_TILES_CONTROLLER_OBJECTS_MAX SCROLLING_TILES_CONTROLLER_OBJECTS_ROW*2
#define SCROLLING_TILES_CONTROLLER_SPACE SPRITE_WIDTH*4
#define SCROLLING_TILES_CONTROLLER_TILE_SPEED 6

struct ScrollingTilesControllerStruct {
    unsigned char objectsCount;    
    GameObject *objects[SCROLLING_TILES_CONTROLLER_OBJECTS_MAX];
};
typedef struct ScrollingTilesControllerStruct ScrollingTilesController;

void ScrollingTilesController_addObject(ScrollingTilesController *scrollingTilesController, GameObject *gameObject) {
    unsigned char objectsCount = scrollingTilesController->objectsCount;
    if (objectsCount >= SCROLLING_TILES_CONTROLLER_OBJECTS_MAX) {
        return;
    }
    scrollingTilesController->objects[objectsCount] = gameObject;
    scrollingTilesController->objectsCount++;
}

void ScrollingTilesController_step(ScrollingTilesController *scrollingTilesController) {
    for (int i = 0; i < SCROLLING_TILES_CONTROLLER_OBJECTS_MAX; i++) {
        scrollingTilesController->objects[i]->x -= SCROLLING_TILES_CONTROLLER_TILE_SPEED;
    }
}

void ScrollingTilesController_initialize(ScrollingTilesController *scrollingTilesController, Renderer *renderer) {
    scrollingTilesController->objectsCount = 0;
    unsigned char x = 0;
    for (int i = 0; i < SCROLLING_TILES_CONTROLLER_OBJECTS_ROW; i++) {
        {
            GameObject *gameObject = GameObjectFactory_static_makeGameObject(x, 0);
            ScrollingTilesController_addObject(scrollingTilesController, gameObject);
            Renderer_addObject(renderer, gameObject);
        }
        {
            GameObject *gameObject = GameObjectFactory_static_makeGameObject(x, 170);
            ScrollingTilesController_addObject(scrollingTilesController, gameObject);
            Renderer_addObject(renderer, gameObject);
        }
        x += SCROLLING_TILES_CONTROLLER_SPACE;
    }
}
