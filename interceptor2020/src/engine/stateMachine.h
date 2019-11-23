struct StateMachineStruct {
    bool isRunning;
    StateController *stateController;
};
typedef struct StateMachineStruct StateMachine;

void StateMachine_initialize(StateMachine *stateMachine) {
    stateMachine->isRunning = false;
    stateMachine->stateController = nullptr;
}

void StateMachine_startWithController(StateMachine *stateMachine, StateController *stateController) {
    stateMachine->isRunning = true;
    stateMachine->stateController = stateController;
}

void StateMachine_step(StateMachine *stateMachine) {
    StateController *stateController = stateMachine->stateController;
    if (stateController == nullptr) {
        return;
    }
    StateController_step(stateController);

    StateController *nextStateController = stateController->nextStateController;
    if (nextStateController != nullptr) {
        stateMachine->stateController = nextStateController;
    }
}
