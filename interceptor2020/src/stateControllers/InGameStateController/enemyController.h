typedef enum {
    EnemyCommandStay,
    EnemyCommandMoveUp,
    EnemyCommandMoveDown,
    EnemyCommandsCount
}
EnemyCommand;

struct EnemyControllerStruct {
    GameObject *enemy;
    EnemyCommand enemyCommand;
    GameObject *bullet;
    Renderer *renderer;
};
typedef struct EnemyControllerStruct EnemyController;

void EnemyController_initialize(EnemyController *enemyController, Renderer *renderer) {
    GameObject *enemy = GameObjectFactory_static_makeGameObject(0, 0);
    GameObject *bullet = GameObjectFactory_static_makeGameObject(0, 0);
    enemyController->enemy = enemy;
    enemyController->enemyCommand = EnemyCommandStay;
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
    enemy->y = randomUnsignedCharMaximal(130);
}

void EnemyController_fireBulletIfNeeded(EnemyController *enemyController) {
    int random = rand();
    GameObject *enemy = enemyController->enemy;
    GameObject *bullet = enemyController->bullet;
    if (random > 3000 && GameObject_isHidden(bullet) == true) {
        playBulletFireSound();
        bullet->x = enemy->x;
        bullet->y = enemy->y;
    }
}

void EnemyController_changeCurrentEnemyCommand(EnemyController *enemyController) {
    EnemyCommand command = randomUnsignedCharMaximal(EnemyCommandsCount);
    enemyController->enemyCommand = command;
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
    if (random < 2000) {
        EnemyController_changeCurrentEnemyCommand(enemyController);
    }

    EnemyCommand command = enemyController->enemyCommand;
    switch (command) {
    case EnemyCommandStay:
        break;
    case EnemyCommandMoveUp:
        if (enemy->y > 0) {
            enemy->y--;
        }
        break;
    case EnemyCommandMoveDown:
        if (enemy->y < 160) {
            enemy->y++;
        }
        break;
    case EnemyCommandsCount:
        break;
    }
}

void EnemyController_bulletFlyIfNeeded(EnemyController *enemyController) {
    GameObject *bullet = enemyController->bullet;
    if (GameObject_isHidden(bullet) == true) {
        return;
    }
    if (bullet->x > 8) {
        bullet->x -= 8;
    }
    else {
        GameObject_hide(bullet);
    }
}

void EnemyController_step(EnemyController *enemyController) {
    if (GameObject_isHidden(enemyController->enemy) == true && rand() < 200) {
        EnemyController_putEnemyIfNeeded(enemyController);
    }
    EnemyController_enemyStepIfNeeded(enemyController);
    EnemyController_bulletFlyIfNeeded(enemyController);
}
