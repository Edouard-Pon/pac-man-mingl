#ifndef PACMAN_MINGL_GAME_H
#define PACMAN_MINGL_GAME_H

#include <iostream>
#include "mingl/gui/sprite.h"
#include "mingl/mingl.h"
#include "mingl/shape/circle.h"
#include "mingl/shape/triangle.h"
#include "mingl/shape/line.h"
#include "mingl/graphics/vec2d.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;


class Game {

public:
    Game();
    ~Game();

    void init(const string &title, int xPos, int yPos, int width, int height);

    void handleEvents();
    void update();
    bool running() { return isRunning; }
    void render();
    void clean();

private:
    bool isRunning;
    MinGL *window;

};


#endif
