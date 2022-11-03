#ifndef PACMAN_MINGL_GAME_H
#define PACMAN_MINGL_GAME_H

#include <iostream>
#include "mingl/gui/sprite.h"
#include "mingl/mingl.h"

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

};


#endif
