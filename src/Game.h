#ifndef PACMAN_MINGL_GAME_H
#define PACMAN_MINGL_GAME_H

#include <iostream>
#include <vector>
#include "mingl/gui/sprite.h"
#include "mingl/gui/text.h"
#include "mingl/shape/rectangle.h"
#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"
#include "GameObject.h"
#include "Map.h"
#include "SpriteManager.h"
#include "Collision.h"


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
    bool isMainMenu;
    bool isGameWon;
    bool isGameLost;
    bool isResetGameLevel;
    MinGL *window;
    GameObject* player;
    Map* levelMap;
    vector<unique_ptr<GameObject>> wallColliders;
    vector<unique_ptr<GameObject>> pointColliders;
    vector<unique_ptr<GameObject>> invisibleHitBoxColliders;
    vector<unique_ptr<GameObject>> enemyColliders;
    Text* scoreText;
    GameObject* mainMenuBackground;
    GameObject* selector;
    unsigned selectorCount;
    unsigned selectorTimer;
    Text* debugGameWonText;
    Text* debugGameLostText;
    Text* debugGameMainMenuText;
    nsShape::Rectangle* scoreRect;

};


#endif
