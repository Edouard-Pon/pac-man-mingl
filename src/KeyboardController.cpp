/*!
 * @file KeyboardController.cpp
 * @brief Keyboard Controller Class
 */

#include "KeyboardController.h"

void KeyboardController::resetAllKeys(MinGL *window, char keyUp, char keyDown,
                                      char keyLeft, char keyRight, char keySelect) {
    window->resetKey({keyUp, false});
    window->resetKey({keyDown, false});
    window->resetKey({keyLeft, false});
    window->resetKey({keyRight, false});
    window->resetKey({keySelect, false});
}
