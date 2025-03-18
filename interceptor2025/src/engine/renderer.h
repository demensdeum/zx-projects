#define RENDERER_MAX_GAME_OBJECTS 16

struct RendererStruct {
    GameObject *gameObjects[RENDERER_MAX_GAME_OBJECTS];
};
typedef struct RendererStruct Renderer;

void Renderer_removeAllGameObjects(Renderer *renderer);
struct sp1_Rect Renderer_fullScreenRect = {0, 0, 32, 24};

void Renderer_initialize(Renderer *renderer) {
    zx_border(INK_BLACK);
    sp1_Initialize( SP1_IFLAG_MAKE_ROTTBL | SP1_IFLAG_OVERWRITE_TILES | SP1_IFLAG_OVERWRITE_DFILE,
                    INK_BLUE | PAPER_WHITE,
                    ' ' );
    sp1_Invalidate(&Renderer_fullScreenRect);

    for (unsigned char i = 0; i < RENDERER_MAX_GAME_OBJECTS; i++) {
        renderer->gameObjects[i] = nullptr;
    }
}

void Renderer_removeGameObject(Renderer *renderer, GameObject *gameObjectToRemove) {
    for (unsigned char i = 0; i < RENDERER_MAX_GAME_OBJECTS; i++) {
        GameObject *gameObject = renderer->gameObjects[i];
        if (gameObject == gameObjectToRemove) {
            GameObject_release(gameObject);
            renderer->gameObjects[i] = nullptr;
        }
    }
}

void Renderer_removeAllGameObjects(Renderer *renderer) {
    for (unsigned char i = 0; i < RENDERER_MAX_GAME_OBJECTS; i++) {
        GameObject *gameObject = renderer->gameObjects[i];
        if (gameObject != nullptr) {
            GameObject_release(gameObject);
            renderer->gameObjects[i] = nullptr;
        }
    }
}

void Renderer_deinitialize(Renderer *renderer) {
    Renderer_removeAllGameObjects(renderer);
}

void Renderer_addGameObject(Renderer *renderer, GameObject *gameObject) {
    for (unsigned char i = 0; i < RENDERER_MAX_GAME_OBJECTS; i++) {
        GameObject *slot = renderer->gameObjects[i];
        if (slot == nullptr) {
            renderer->gameObjects[i] = gameObject;
            GameObject_retain(gameObject);
            break;
        }
    }
}

void Renderer_renderGameObjects(Renderer *renderer) {
    for (unsigned char i = 0; i < RENDERER_MAX_GAME_OBJECTS; i++) {
        GameObject *gameObject = renderer->gameObjects[i];
        if (gameObject == nullptr) {
            return;
        }
        sp1_MoveSprPix(gameObject->gameObjectSprite, Renderer_fullScreenRect, gameObject->sprite_col, gameObject->x, gameObject->y);
    }
}

void Renderer_clearScreen(Renderer *renderer) {
    sp1_ClearRectInv(Renderer_fullScreenRect, BRIGHT | INK_BLACK | PAPER_BLACK, 32, SP1_RFLAG_TILE | SP1_RFLAG_COLOUR);
}

void Renderer_renderFullscreenImage(Renderer *renderer, FullscreenImage *fullscreenImage) {
    Renderer_clearScreen(renderer);

    unsigned char i;
    unsigned char *pt = fullscreenImage->tiles;

    for (i = 0; i < fullscreenImage->tilesLength; i++, pt += 8) {
        sp1_TileEntry(fullscreenImage->tilesBase + i, pt);
    }

    struct sp1_pss ps0;

    ps0.bounds    = &Renderer_fullScreenRect;
    ps0.flags     = SP1_PSSFLAG_INVALIDATE;
    ps0.visit     = 0;

    sp1_SetPrintPos(&ps0, 0, 0);
    sp1_PrintString(&ps0, fullscreenImage->ptiles);
}

void Renderer_updateScreen(Renderer *renderer) {
    sp1_UpdateNow();
}

void Renderer_renderText(Renderer *render, char *text, unsigned char x, unsigned char y) {
    struct sp1_pss ps0;
    ps0.bounds    = &Renderer_fullScreenRect;
    ps0.flags     = SP1_PSSFLAG_INVALIDATE;
    ps0.visit     = 0;

    sp1_SetPrintPos(&ps0, y, x);
    sp1_PrintString(&ps0, text);
}
