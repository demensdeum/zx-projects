struct StateControllerStruct {
     void *nextStateController;
     void *subclassInstance;
     void (*subclassStepFunction)(void *);
};
typedef struct StateControllerStruct StateController;

void StateController_step(StateController *stateController) {
    void (*subclassStepFunction)(void *) = stateController->subclassStepFunction;
    if (subclassStepFunction == nullptr) {
        return;
    }  
    void *subclassInstance = stateController->subclassInstance;
    if (subclassInstance == nullptr) {
        return;
    }
    subclassStepFunction(subclassInstance);
}
