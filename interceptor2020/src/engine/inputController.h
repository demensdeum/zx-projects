#include <input.h>

struct InputControllerStruct {
    bool isUpButtonPressed;
    bool isDownButtonPressed;
    bool isFireButtonPressed;
};
typedef struct InputControllerStruct InputController;

void InputController_reset(InputController *inputController) {
    inputController->isUpButtonPressed = false;
    inputController->isDownButtonPressed = false;
    inputController->isFireButtonPressed = false;
}

void InputController_initialize(InputController *inputController) {
    InputController_reset(inputController);
}

void InputController_step(InputController *inputController) {
    InputController_reset(inputController);
    if (in_key_pressed(IN_KEY_SCANCODE_w)) {
        inputController->isUpButtonPressed = true;
    }
    else if (in_key_pressed(IN_KEY_SCANCODE_s)) {
        inputController->isDownButtonPressed = true;
    }
    if (in_key_pressed(IN_KEY_SCANCODE_SPACE)) {
        inputController->isFireButtonPressed = true;
    }
}
