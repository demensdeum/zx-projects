struct GameObjectStruct {
  struct sp1_ss *gameObjectSprite;
  unsigned char x;
  unsigned char y;
};
typedef struct GameObjectStruct GameObject;

void GameObject_initialize(GameObject *gameObject, struct sp1_ss *gameObjectSprite, unsigned char x, unsigned char y) {
    gameObject->gameObjectSprite = gameObjectSprite;
    gameObject->x = x;
    gameObject->y = y;
}
