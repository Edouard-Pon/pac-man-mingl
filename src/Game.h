#ifndef PACMAN_MINGL_GAME_H
#define PACMAN_MINGL_GAME_H

#include <iostream>
#include "mingl/gui/sprite.h"
#include "mingl/mingl.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"
#include "mingl/shape/line.h"

using namespace std;
using namespace nsShape;
using namespace nsGraphics;


class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height);

    void handleEvents();
    void update();
    bool running() { return isRunning; }
    void render();
    void clean();

private:
    int count = 0;
    bool isRunning;
    MinGL *window;

    int testX = 300;
    int testY = 300;

    int triOne2X = 422;
    int triOne2Y = 212;
    int triTwo2X = 443;
    int triTwo2Y = 254;

    int triFourth3X = 422;
    int triFourth3Y = 388;
    int triThree3X = 443;
    int triThree3Y = 350;

    bool triOneF = true;
    bool triOneB = false;
    bool triTwoF = false;
    bool triTwoB = false;

    int moveX = 0;
    int moveY = 0;

};


#endif
