#ifndef PACMAN_MINGL_SPRITEMANAGER_H
#define PACMAN_MINGL_SPRITEMANAGER_H

#include "Game.h"


class SpriteManager {

public:
    static Sprite* LoadSprite(const string &fileName, int x, int y);

};


#endif
