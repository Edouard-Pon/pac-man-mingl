/*!
 * @file SpriteManager.h
 * @brief Sprite Manager Class
 */

#ifndef PACMAN_MINGL_SPRITEMANAGER_H
#define PACMAN_MINGL_SPRITEMANAGER_H

#include "Game.h"

/*!
 * @brief Sprite Manager Class
 */
class SpriteManager {

public:
    /*!
     * @brief return generated sprite
     * @param fileName
     * @param x
     * @param y
     * @return sprite;
     */
    static Sprite* LoadSprite(const string &fileName, int x, int y);

};


#endif
