#include "Collision.h"

bool Collision::AABB(const Vec2D &vecA, const Vec2D &vecB, const unsigned width, const unsigned height) {
    if (
            vecA.getX() + width > vecB.getX() &&
            vecB.getX() + width > vecA.getX() &&
            vecA.getY() + height > vecB.getY() &&
            vecB.getY() + height > vecA.getY()
            ) {
        return true;
    }
    return false;
}
