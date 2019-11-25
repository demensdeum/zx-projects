struct SpaceMinesControllerStruct {
    GameObject *spaceMineOne;
    GameObject *spaceMineTwo;
    Renderer *renderer;
};
typedef struct SpaceMinesControllerStruct SpaceMinesController;

void SpaceMinesController_initialize(SpaceMinesController *spaceMinesController, Renderer *renderer) {
    GameObject *spaceMineOne = GameObjectFactory_static_makeGameObject(0, 0, mine_col1, mine_col2);
    GameObject *spaceMineTwo = GameObjectFactory_static_makeGameObject(0, 0, mine_col1, mine_col2);
    spaceMinesController->spaceMineOne = spaceMineOne;
    spaceMinesController->spaceMineTwo = spaceMineTwo;
    spaceMinesController->renderer = renderer;

    GameObject_hide(spaceMineOne);
    GameObject_hide(spaceMineTwo);

    Renderer_addGameObject(renderer, spaceMineOne);
    Renderer_addGameObject(renderer, spaceMineTwo);
}

void SpaceMinesController_deinitialize(SpaceMinesController *spaceMinesController, Renderer *renderer) {
    Renderer *renderer = spaceMinesController->renderer;

    GameObject_release(spaceMinesController->spaceMineOne);
    GameObject_release(spaceMinesController->spaceMineTwo);

    Renderer_removeGameObject(renderer, spaceMinesController->spaceMineOne);
    Renderer_removeGameObject(renderer, spaceMinesController->spaceMineTwo);
}

void SpaceMinesController_putMineOneIfNeeded(SpaceMinesController *spaceMinesController) {
    GameObject *spaceMineOne = spaceMinesController->spaceMineOne;
    if (GameObject_isHidden(spaceMineOne)) {
        spaceMineOne->x = 254;
        spaceMineOne->y = randomUnsignedCharMaximal(160);
    }
}

void SpaceMinesController_putMineTwoIfNeeded(SpaceMinesController *spaceMinesController) {
    GameObject *spaceMineTwo = spaceMinesController->spaceMineTwo;
    if (GameObject_isHidden(spaceMineTwo)) {
        spaceMineTwo->x = 254;
        spaceMineTwo->y = randomUnsignedCharMaximal(160);
    }
}

void SpaceMinesController_step(SpaceMinesController *spaceMinesController) {
    int random = rand();

    if (random < 100) {
        SpaceMinesController_putMineOneIfNeeded(spaceMinesController);
    }
    else if (random < 200) {
        SpaceMinesController_putMineTwoIfNeeded(spaceMinesController);
    }
    else {
        if (spaceMinesController->spaceMineOne->x > 4) {
            spaceMinesController->spaceMineOne->x -= 4;
        }
        else {
            GameObject_hide(spaceMinesController->spaceMineOne);
        }
        if (spaceMinesController->spaceMineTwo->x > 4) {
            spaceMinesController->spaceMineTwo->x -= 4;
        }
        else {
            GameObject_hide(spaceMinesController->spaceMineTwo);
        }
    }
}
