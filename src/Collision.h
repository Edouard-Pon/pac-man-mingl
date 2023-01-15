/*!
 * @file Collision.h
 * @brief Collision Class detect collision
 */

#ifndef PACMAN_MINGL_COLLISION_H
#define PACMAN_MINGL_COLLISION_H

#include "mingl/graphics/vec2d.h"

using namespace nsGraphics;

/*!
 * @brief Collision Class
 */
class Collision {
    
public:
    /*!
     * @brief AABB Collision system. Detect collision between two objects
     * @param vecA
     * @param vecB
     * @param width
     * @param height
     * @return
     */
    static bool AABB(const Vec2D& vecA, const Vec2D& vecB, const unsigned width, const unsigned height);
    
};


#endif
