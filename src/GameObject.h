#ifndef PACMAN_MINGL_GAMEOBJECT_H
#define PACMAN_MINGL_GAMEOBJECT_H

#include <iostream>
#include "mingl/gui/sprite.h"
#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;

class GameObject {

public:
    GameObject(const string &fileName, MinGL* win, int x, int y);
    ~GameObject();

    void Update();
    void Render();
    void Move(bool isPlayer);
    Vec2D getPos();
    void setPos(int x, int y);
    void resetObjectDirection();
    void setInvisible();
    void killObject();
    void addScore();
    bool isInvisible() const;
    unsigned getScore() const;
    void setObjectDirection(unsigned direction);
    void setTempPosition();
    Vec2D getTempPosition();
    void setMovementSpeed(int speed);

private:
    int xPos;
    int yPos;
    Vec2D tempPosition;

    struct {
        bool up = false;
        bool down = false;
        bool right = false;
        bool left = false;
        bool invisible = false;
        bool dead = false;
        unsigned score = 0;
        int movementSpeed = 5;
    } objectProperty;

    Sprite* sprite;
    MinGL* window;

};


#endif
