#include <input.h>

struct InputControllerStruct {
    unsigned char upButtonPressed;
    unsigned char downButtonPressed;
    unsigned char fireButtonPressed;
};
typedef struct InputControllerStruct InputController;

void inputController_reset(InputController *inputController) {
    inputController->upButtonPressed = false;
    inputController->downButtonPressed = false;
    inputController->fireButtonPressed = false;
}

void inputController_initialize(InputController *inputController) {
    inputController_reset(inputController);
}

void inputController_step(InputController *inputController) {
    inputController_reset(inputController);
      if (in_key_pressed(IN_KEY_SCANCODE_w)) {
          inputController->upButtonPressed = true;
      }
      else if (in_key_pressed(IN_KEY_SCANCODE_s)) {
          inputController->downButtonPressed = true;
      }
}
