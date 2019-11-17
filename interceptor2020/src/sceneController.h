struct SceneControllerStruct {
  GameObject *playerControlledGameObject;
  GameObject *bulletGameObject;
  InputController *inputController;
  unsigned char bulletShouldFly;
};
typedef struct SceneControllerStruct SceneController;

void SceneController_initialize(SceneController *sceneController, GameObject *playerControlledGameObject, GameObject *bulletGameObject, InputController *inputController) {
    sceneController->playerControlledGameObject = playerControlledGameObject;
    sceneController->bulletGameObject = bulletGameObject;
    sceneController->inputController = inputController;
    sceneController->bulletShouldFly = false;
}

void SceneController_step(SceneController *sceneController) {
    GameObject *bulletGameObject = sceneController->bulletGameObject;
    GameObject *playerControlledGameObject = sceneController->playerControlledGameObject;
    InputController *inputController = sceneController->inputController;
    if (inputController->upButtonPressed) {
        playerControlledGameObject->y--;
    }
    else if (inputController->downButtonPressed) {
        playerControlledGameObject->y++;
    }
    if (inputController->fireButtonPressed) {
        sceneController->bulletShouldFly = true;
    }
    if (sceneController->bulletShouldFly && bulletGameObject->x < 228) {
        bulletGameObject->x += 6;
    }
    else {
        sceneController->bulletShouldFly = false;
        bulletGameObject->x = playerControlledGameObject->x;
        bulletGameObject->y = playerControlledGameObject->y;
    }
}
