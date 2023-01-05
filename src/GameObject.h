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
    void Move();
    Vec2D getPos();
    void setPos(const int x, const int y);

private:
    int xPos;
    int yPos;

    Sprite* sprite;
    MinGL* window;

};


#endif
