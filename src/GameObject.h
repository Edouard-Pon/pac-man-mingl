#ifndef PACMAN_MINGL_GAMEOBJECT_H
#define PACMAN_MINGL_GAMEOBJECT_H

#include "Game.h"


class GameObject {

public:
    GameObject(const string &fileName, MinGL* win, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xPos;
    int yPos;

    Sprite* sprite;
    MinGL* window;

};


#endif
