/*!
 * @file KeyboardController.h
 * @brief Keyboard Controller Class
 */

#ifndef PACMAN_MINGL_KEYBOARDCONTROLLER_H
#define PACMAN_MINGL_KEYBOARDCONTROLLER_H

#include "Game.h"

/*!
 * @brief Keyboard Controller Class
 */
class KeyboardController {

public:
     /*!
      * @brief Reset keyboard key handlers
      * @param window
      * @param keyUp
      * @param keyDown
      * @param keyLeft
      * @param keyRight
      * @param keySelect
      * @fn static void resetAllKeys(MinGL* window);
      */
    static void resetAllKeys(MinGL* window, char keyUp, char keyDown,
                             char keyLeft, char keyRight, char keySelect);
};


#endif
