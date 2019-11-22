struct EnemyControllerStruct {
     GameObject *enemy;
     GameObject *bullet;    
     Renderer *renderer;
};
typedef struct EnemyControllerStruct EnemyController; 

void EnemyController_initialize(EnemyController *enemyController, Renderer *renderer) {
    GameObject *enemy = GameObjectFactory_static_makeGameObject(0, 0);
    GameObject *bullet = GameObjectFactory_static_makeGameObject(0, 0);
    enemyController->enemy = enemy;
    enemyController->bullet = bullet;
    enemyController->renderer = renderer;
    
    GameObject_hide(enemy);
    GameObject_hide(bullet);
    
    Renderer_addGameObject(renderer, enemy);
    Renderer_addGameObject(renderer, bullet);
}

void EnemyController_deinitialize(EnemyController *enemyController, Renderer *renderer) {
    Renderer *renderer = enemyController->renderer;
    
    GameObject_release(enemyController->enemy);
    GameObject_release(enemyController->bullet);
    
    Renderer_removeGameObject(renderer, enemyController->enemy);
    Renderer_removeGameObject(renderer, enemyController->bullet);    
}

void EnemyController_putEnemyIfNeeded(EnemyController *enemyController) {
    GameObject *enemy = enemyController->enemy;
    if (GameObject_isHidden(enemy) == false) {
        return;
    }
    enemy->x = 240;
    enemy->y = rand() / 254;
}

void EnemyController_fireBulletIfNeeded(EnemyController *enemyController) {
    int random = rand();
    if (random > 3000) {
        playBulletFireSound();
    }
}

void EnemyController_enemyStepIfNeeded(EnemyController *enemyController) {
   GameObject *enemy = enemyController->enemy;
    if (GameObject_isHidden(enemy)) {
        return;
    }
    int random = rand();
    if (random < 1000) {
        EnemyController_fireBulletIfNeeded(enemyController);
    }
}

void EnemyController_putMineTwoIfNeeded(EnemyController *enemyController) {
    GameObject *bullet = enemyController->bullet;
    if (GameObject_isHidden(bullet)) {
        bullet->x = 254;
        bullet->y = rand() / 180;
    }    
}

void EnemyController_step(EnemyController *enemyController) {
    int random = rand();
    if (random < 1000) {
        EnemyController_putEnemyIfNeeded(enemyController);
    }
    EnemyController_enemyStepIfNeeded(enemyController);    
} 
