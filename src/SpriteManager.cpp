/*!
 * @file SpriteManager.cpp
 * @brief Sprite Manager Class
 */

#include "SpriteManager.h"


Sprite *SpriteManager::LoadSprite(const string &fileName, const int x, const int y) {
    Sprite* sprite = new Sprite(fileName, { x, y });

    return sprite;
}
