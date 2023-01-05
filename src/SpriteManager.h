#ifndef PACMAN_MINGL_SPRITEMANAGER_H
#define PACMAN_MINGL_SPRITEMANAGER_H

#include "Game.h"


class SpriteManager {

public:
    static Sprite* LoadSprite(const string &fileName, const Vec2D& position);
    static void Draw(MinGL& window, Sprite* spr, Vec2D& coordinates);

};


#endif
