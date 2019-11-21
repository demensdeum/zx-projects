 struct StateMachineStruct {
     StateController *stateController;
     bool isRunning;
};
typedef struct StateMachineStruct StateMachine;

void StateMachine_run(StateMachine *stateMachine) {
    stateMachine->stateController = 0;
    stateMachine->isRunning = true;
}
