struct InterceptorControllerStruct {
    GameObject *interceptor;
    GameObject *bullet;
    InputController *inputController;
    bool isBulletShouldFly;
};
typedef struct InterceptorControllerStruct InterceptorController;

void InterceptorController_initialize(InterceptorController *interceptorController, Renderer *renderer) {
    GameObject *interceptor = GameObjectFactory_static_makeGameObject(0, 0);
    GameObject *bullet = GameObjectFactory_static_makeGameObject(0, 0);
    interceptorController->interceptor = interceptor;
    interceptorController->bullet = bullet;

    interceptorController->isBulletShouldFly = false;

    GameObject_retain(interceptor);
    GameObject_retain(bullet);

    Renderer_addGameObject(renderer, interceptor);
    Renderer_addGameObject(renderer, bullet);
    GameObject_hide(bullet);

    InputController *inputController = new(InputController);
    InputController_initialize(inputController);
    interceptorController->inputController = inputController;
}

void InterceptorController_deinitialize(InterceptorController *interceptorController, Renderer *renderer) {
    GameObject_release(interceptorController->interceptor);
    GameObject_release(interceptorController->bullet);

    Renderer_removeGameObject(renderer, interceptorController->interceptor);
    Renderer_removeGameObject(renderer, interceptorController->bullet);

    delete(interceptorController->inputController);
}

void InterceptorController_step(InterceptorController *interceptorController) {
    InputController *inputController = interceptorController->inputController;
    InputController_step(inputController);

    GameObject *interceptor = interceptorController->interceptor;
    GameObject *bullet = interceptorController->bullet;

    if (inputController->isDownButtonPressed == true && interceptor->y < 160) {
        interceptor->y += 4;
    }
    else if (inputController->isUpButtonPressed == true && interceptor->y > 0) {
        interceptor->y -= 4;
    }
    interceptorController->isBulletShouldFly = (inputController->isFireButtonPressed == true || bullet->x > 0);

    if (interceptorController->isBulletShouldFly == true) {
        if (bullet->x == 0) {
            GameObject_show(bullet);
            playBulletFireSound();
            bullet->x = 8;
            bullet->y = interceptor->y;
        }
        else if (bullet->x > 240) {
            GameObject_hide(bullet);
            bullet->x = 0;
        }
        else {
            bullet->x += 8;
        }
    }
}
