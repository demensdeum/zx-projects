struct SceneControllerStruct {
  GameObject *playerControlledGameObject;
  InputController *inputController;
};
typedef struct SceneControllerStruct SceneController;

void SceneController_initialize(SceneController *sceneController, GameObject *playerControlledGameObject, InputController *inputController) {
    sceneController->playerControlledGameObject = playerControlledGameObject;
    sceneController->inputController = inputController;
}

void SceneController_step(SceneController *sceneController) {
    GameObject *playerControlledGameObject = sceneController->playerControlledGameObject;
    InputController *inputController = sceneController->inputController;
    if (inputController->upButtonPressed) {
        playerControlledGameObject->y--;
    }
    else if (inputController->downButtonPressed) {
        playerControlledGameObject->y++;
    }    
}
