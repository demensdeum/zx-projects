 struct InGameControllerStruct {
     GameObject *interceptor;
     GameObject *bullet;
};
typedef struct InGameControllerStruct InGameController;

void InGameController_initialize() {
  GameObject *interceptor = GameObjectFactory_static_makeGameObject(8, 8);
  GameObject *bullet = GameObjectFactory_static_makeGameObject(8, 8);

  InputController inputController;
  InputController_initialize(&inputController);  
  
  SceneController sceneController;
  SceneController_initialize(&sceneController, interceptor, bullet, &inputController);
  
  Renderer renderer;
  Renderer_initialize(&renderer, &full_screen);
  Renderer_addObject(&renderer, interceptor);
  Renderer_addObject(&renderer, bullet);
  
  ScrollingTilesController scrollingTilesController;
  ScrollingTilesController_initialize(&scrollingTilesController, &renderer);
  
  EnemiesController enemiesController;
  EnemiesController_initialize(&enemiesController, &renderer);
  
  while(true)
  {      
    InputController_step(&inputController);
    SceneController_step(&sceneController);
    ScrollingTilesController_step(&scrollingTilesController);
    EnemiesController_step(&enemiesController);
    
    Renderer_render(&renderer);

    sp1_UpdateNow();
  }
  
}
