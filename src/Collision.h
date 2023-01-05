#ifndef PACMAN_MINGL_COLLISION_H
#define PACMAN_MINGL_COLLISION_H

#include "mingl/graphics/vec2d.h"

using namespace nsGraphics;


class Collision {
    
public:
    static bool AABB(const Vec2D& vecA, const Vec2D& vecB, const unsigned width, const unsigned height);
    
};


#endif
