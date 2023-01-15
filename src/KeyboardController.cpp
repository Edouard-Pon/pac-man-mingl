/*!
 * @file KeyboardController.cpp
 * @brief Keyboard Controller Class
 */

#include "KeyboardController.h"

void KeyboardController::resetAllKeys(MinGL *window) {
    window->resetKey({'w', false});
    window->resetKey({'s', false});
    window->resetKey({'a', false});
    window->resetKey({'d', false});
    window->resetKey({'e', false});
}
