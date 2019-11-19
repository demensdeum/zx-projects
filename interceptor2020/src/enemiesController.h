 struct EnemiesControllerStruct {
     GameObject *enemy;
     GameObject *bullet;
     unsigned char shouldMoveUp;
     unsigned char moveStep;
};
typedef struct EnemiesControllerStruct EnemiesController;

void EnemiesController_initialize(EnemiesController *enemiesController, Renderer *renderer) {
    GameObject *enemy = GameObjectFactory_static_makeGameObject(228, 148);
    GameObject *bullet = GameObjectFactory_static_makeGameObject(228, 148);
    enemiesController->enemy = enemy;
    enemiesController->bullet = bullet;
    Renderer_addObject(renderer, enemy);
    Renderer_addObject(renderer, bullet);
    
    enemiesController->shouldMoveUp = true;
    enemiesController->moveStep = 8;
}

void EnemiesController_step(EnemiesController *enemiesController) {
    GameObject *enemy = enemiesController->enemy;
    
    if (enemiesController->moveStep > 0) {
        if (enemiesController->shouldMoveUp) {
            enemy->y -= 16;
        }
        else {
            enemy->y += 16;
        }
        enemiesController->moveStep--;
    }
    else {
        enemiesController->moveStep = 8;
        enemiesController->shouldMoveUp = !enemiesController->shouldMoveUp;
    }
    
    GameObject *bullet = enemiesController->bullet;
    bullet->x -= 22;
    
    if (bullet->x <=10) {
        bullet->x = enemy->x;        
        bullet->y = enemy->y;
    }
}
