#ifndef PACMAN_MINGL_GAMEOBJECT_H
#define PACMAN_MINGL_GAMEOBJECT_H

#include <iostream>
#include <thread>
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
    void setVisible();
    void killObject();
    void addScore();
    bool isInvisible() const;
    unsigned getScore() const;
    void setObjectDirection(unsigned direction);
    void setTempPosition();
    Vec2D getTempPosition();
    void setMovementSpeed(int speed);
    void resetPosition();
    void reviveObject();
    void resetScore();
    void setLives(unsigned lives);
    unsigned getLives() const;
    void setInvincible(bool isInvincible);
    bool isInvincible() const;
    void setTimer();
    unsigned getTimer();
    unsigned getInvAnimation() const;
    void setInvAnimation(unsigned currentTimer);

private:
    int xPos;
    int yPos;
    int xInitialPosition;
    int yInitialPosition;
    Vec2D tempPosition;
    chrono::time_point<chrono::steady_clock> timer;
    unsigned invAnimation = 0;

    struct {
        bool up = false;
        bool down = false;
        bool right = false;
        bool left = false;
        bool invisible = false;
        bool dead = false;
        unsigned score = 0;
        int movementSpeed = 5;
        unsigned lives = 3;
        bool invincible = false;
    } objectProperty;

    Sprite* sprite;
    MinGL* window;

};


#endif
