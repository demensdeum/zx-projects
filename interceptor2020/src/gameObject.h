struct GameObjectStruct {
  unsigned char x;
  unsigned char y;
};
typedef struct GameObjectStruct GameObject;

void GameObject_initialize(GameObject *gameObject, unsigned char x, unsigned char y) {
    gameObject->x = x;
    gameObject->y = y;
}
