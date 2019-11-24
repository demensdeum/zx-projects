struct ColliderControllerStruct {
    GameObject *interceptor;
    GameObject *mineOne;
    GameObject *mineTwo;
    GameObject *enemyBullet;
    GameObject *interceptorBullet;
    GameObject *enemy;
    void *delegate;
    void (*colliderControllerMineCollidesWithInterceptor)(void *, void *, GameObject *, GameObject *);
    void (*colliderControllerEnemyBulletCollidesWithInterceptor)(void *, void *, GameObject *, GameObject *);
    void (*colliderControllerInterceptorBulletCollidesWithEnemy)(void *, void *, GameObject *, GameObject *);
    void (*colliderControllerMineCollidesWithInterceptorBullet)(void *, void *, GameObject *, GameObject *);
};
typedef struct ColliderControllerStruct ColliderController;

unsigned int Collider_ControllerSpriteWidth = 16;
unsigned int Collider_ControllerSpriteHeight = 16;

void ColliderController_initialize(
    ColliderController *colliderController, 
    GameObject *interceptor, 
    GameObject *mineOne, 
    GameObject *mineTwo, 
    GameObject *enemyBullet,
    GameObject *interceptorBullet,
    GameObject *enemy,
    void *delegate, 
    void (*colliderControllerMineCollidesWithInterceptor)(void *, void *, GameObject *, GameObject *),
    void (*colliderControllerEnemyBulletCollidesWithInterceptor)(void *, void *, GameObject *, GameObject *),
    void (*colliderControllerInterceptorBulletCollidesWithEnemy)(void *, void *, GameObject *, GameObject *),
    void (*colliderControllerMineCollidesWithInterceptorBullet)(void *, void *, GameObject *, GameObject *)
) {    
    colliderController->interceptor = interceptor;
    colliderController->mineOne = mineOne;
    colliderController->mineTwo = mineTwo;
    colliderController->enemyBullet = enemyBullet;
    colliderController->interceptorBullet = interceptorBullet;
    colliderController->enemy = enemy;
    colliderController->delegate = delegate;
    colliderController->colliderControllerMineCollidesWithInterceptor = colliderControllerMineCollidesWithInterceptor;
    colliderController->colliderControllerEnemyBulletCollidesWithInterceptor = colliderControllerEnemyBulletCollidesWithInterceptor;
    colliderController->colliderControllerInterceptorBulletCollidesWithEnemy = colliderControllerInterceptorBulletCollidesWithEnemy;
    colliderController->colliderControllerMineCollidesWithInterceptorBullet = colliderControllerMineCollidesWithInterceptorBullet;
    
    GameObject_retain(interceptor);
    GameObject_retain(mineOne);
    GameObject_retain(mineTwo);
    GameObject_retain(enemyBullet);
}

void ColliderController_deinitialize(ColliderController *colliderController) {
    GameObject_release(colliderController->interceptor);
    GameObject_release(colliderController->mineOne);
    GameObject_release(colliderController->mineTwo);
    GameObject_release(colliderController->enemyBullet);
}

bool ColliderController_isCollides(ColliderController *colliderController, GameObject *aGameObject, GameObject *bGameObject) {
    unsigned int aX = aGameObject->x;
    unsigned int aY = aGameObject->y;
    unsigned int aXX = aGameObject->x + Collider_ControllerSpriteWidth;
    unsigned int aYY = aGameObject->y + Collider_ControllerSpriteHeight;
    
    unsigned int bX = bGameObject->x;
    unsigned int bY = bGameObject->y;
    unsigned int bXX = bGameObject->x + Collider_ControllerSpriteWidth;
    unsigned int bYY = bGameObject->y + Collider_ControllerSpriteHeight;
    
    if (aX > bXX) {
        return false;
    }
    
    if (aY > bYY) {
        return false;
    }    
    
    if (aXX < bX) {
        return false;
    }
    
    if (aYY < bY) {
        return false;
    }
    
    return true;
}

void ColliderController_step(ColliderController *colliderController) {
    GameObject *mineOne = colliderController->mineOne;
    GameObject *mineTwo = colliderController->mineTwo;
    
    bool isMineOneCollidesWithInterceptor = GameObject_isHidden(mineOne) == false && ColliderController_isCollides(colliderController, colliderController->interceptor, mineOne);
    bool isMineTwoCollidesWithInterceptor = GameObject_isHidden(mineTwo) == false && ColliderController_isCollides(colliderController, colliderController->interceptor, mineTwo);
    
    if (isMineOneCollidesWithInterceptor) {
        colliderController->colliderControllerMineCollidesWithInterceptor(colliderController->delegate, 
                                                                          colliderController, 
                                                                          mineOne, 
                                                                          colliderController->interceptor);
    }
    else if (isMineTwoCollidesWithInterceptor) {
        colliderController->colliderControllerMineCollidesWithInterceptor(colliderController->delegate, 
                                                                          colliderController, 
                                                                          mineTwo, 
                                                                          colliderController->interceptor);        
    }
    
    GameObject *enemyBullet = colliderController->enemyBullet;
    
    bool isEnemyBulletCollidesWithInterceptor = GameObject_isHidden(enemyBullet) == false && ColliderController_isCollides(colliderController, colliderController->enemyBullet, colliderController->interceptor);
    
    if (isEnemyBulletCollidesWithInterceptor) {
        colliderController->colliderControllerEnemyBulletCollidesWithInterceptor(colliderController->delegate, 
                                                                                 colliderController, 
                                                                                 enemyBullet, 
                                                                                 colliderController->interceptor);
    }
    
    GameObject *interceptorBullet = colliderController->interceptorBullet;
    GameObject *enemy = colliderController->enemy;
    
    bool isInterceptorBulletCollidesWithEnemy = GameObject_isHidden(interceptorBullet) == false && GameObject_isHidden(enemy) == false && ColliderController_isCollides(colliderController, interceptorBullet, enemy);
    
    if (isInterceptorBulletCollidesWithEnemy) {
        colliderController->colliderControllerInterceptorBulletCollidesWithEnemy(colliderController->delegate, 
                                                                                 colliderController, 
                                                                                 interceptorBullet, 
                                                                                 enemy);
    }
    
    bool isMineOneCollidesWithInterceptorBullet = GameObject_isHidden(mineOne) == false && GameObject_isHidden(interceptorBullet) == false && ColliderController_isCollides(colliderController, colliderController->interceptor, mineOne);
    bool isMineTwoCollidesWithInterceptorBullet = GameObject_isHidden(mineTwo) == false && GameObject_isHidden(interceptorBullet) == false && ColliderController_isCollides(colliderController, colliderController->interceptor, mineTwo);
    
    if (isMineOneCollidesWithInterceptorBullet) {
        beep();
        colliderController->colliderControllerMineCollidesWithInterceptorBullet(colliderController->delegate, 
                                                                          colliderController, 
                                                                          mineOne, 
                                                                          colliderController->interceptorBullet);
    }
    else if (isMineTwoCollidesWithInterceptorBullet) {
        beep();
        colliderController->colliderControllerMineCollidesWithInterceptorBullet(colliderController->delegate, 
                                                                          colliderController, 
                                                                          mineTwo, 
                                                                          colliderController->interceptorBullet);        
    }    
}
