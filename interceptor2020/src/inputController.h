#include <input.h>

struct InputControllerStruct {
    bool upButtonPressed;
    bool downButtonPressed;
    bool fireButtonPressed;
};
typedef struct InputControllerStruct InputController;

void InputController_reset(InputController *inputController) {
    inputController->upButtonPressed = false;
    inputController->downButtonPressed = false;
    inputController->fireButtonPressed = false;
}

void InputController_initialize(InputController *inputController) {
    InputController_reset(inputController);
}

void InputController_step(InputController *inputController) {
    InputController_reset(inputController);
      if (in_key_pressed(IN_KEY_SCANCODE_w)) {
          inputController->upButtonPressed = true;
      }
      else if (in_key_pressed(IN_KEY_SCANCODE_s)) {
          inputController->downButtonPressed = true;
      }
      if (in_key_pressed(IN_KEY_SCANCODE_SPACE)) {
          inputController->fireButtonPressed = true;
      }
}
