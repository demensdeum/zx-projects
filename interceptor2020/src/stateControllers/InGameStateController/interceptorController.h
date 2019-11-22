 struct InterceptorControllerStruct {
     GameObject *interceptor;
     GameObject *bullet;
     InputController *inputController;
     Renderer *renderer;
};
typedef struct InterceptorControllerStruct InterceptorController; 

void InterceptorController_initialize(InterceptorController *interceptorController, Renderer *renderer) {
    GameObject *interceptor = GameObjectFactory_static_makeGameObject(0, 0);
    GameObject *bullet = GameObjectFactory_static_makeGameObject(0, 0);
    
    interceptorController->interceptor = interceptor;
    interceptorController->bullet = bullet;
    interceptorController->renderer = renderer;
    
    GameObject_retain(interceptor);
    GameObject_retain(bullet);
    
    Renderer_addGameObject(renderer, interceptorController->interceptor);
    Renderer_addGameObject(renderer, interceptorController->bullet);
    
    InputController *inputController = new(InputController);
    InputController_initialize(inputController);
}

void InterceptorController_deinitialize(InterceptorController *interceptorController) {
    Renderer *renderer = interceptorController->renderer;
    
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
    
    if (inputController->isDownButtonPressed == true) {
        interceptor->y += 10;
    }
    else if (inputController->isUpButtonPressed == true) {
        interceptor->y -= 10;
    }
}
