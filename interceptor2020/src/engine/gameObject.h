struct GameObjectStruct {
  struct sp1_ss *gameObjectSprite;
  unsigned char x;
  unsigned char y;
  unsigned char referenceCount;
  unsigned char beforeHideX;
  unsigned char beforeHideY;
};
typedef struct GameObjectStruct GameObject;

void GameObject_initialize(GameObject *gameObject, struct sp1_ss *gameObjectSprite, unsigned char x, unsigned char y) {
    gameObject->gameObjectSprite = gameObjectSprite;
    gameObject->x = x;
    gameObject->y = y;
    gameObject->referenceCount = 0;
}

void GameObject_retain(GameObject *gameObject) {
    gameObject->referenceCount++;
}

void GameObject_release(GameObject *gameObject) {
    gameObject->referenceCount--;
    
    if (gameObject->referenceCount < 1) {
        sp1_MoveSprAbs(gameObject->gameObjectSprite, &Renderer_fullScreenRect, NULL, 0, 34, 0, 0);
        sp1_DeleteSpr(gameObject->gameObjectSprite);
        delete(gameObject);
    }
}

void GameObject_hide(GameObject *gameObject) {
    gameObject->beforeHideX = gameObject->x;
    gameObject->beforeHideY = gameObject->y;
    gameObject->y = 200;
}

void GameObject_show(GameObject *gameObject) {
    gameObject->x = gameObject->beforeHideX;
    gameObject->y = gameObject->beforeHideY;
}

bool GameObject_isHidden(GameObject *gameObject) {
    return gameObject->y == 200;
}
