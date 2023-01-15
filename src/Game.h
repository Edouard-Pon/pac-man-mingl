/*!
 * @file Game.h
 * @brief Game Class
 */

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
#include "KeyboardController.h"


using namespace std;
using namespace nsGraphics;
using namespace nsGui;

/*!
 * @brief Game Class
 */
class Game {

public:
    /*!
     * @brief Constructor for Game Class
     * @fn Game();
     */
    Game();

    /*!
     * @brief Destructor for Game Class
     * @fn ~Game();
     */
    ~Game();

    /*!
     * @brief Initialize the Game
     * @param title
     * @param xPos
     * @param yPos
     * @param width
     * @param height
     * @fn void init(const string &title, int xPos, int yPos, int width, int height);
     */
    void init(const string &title, int xPos, int yPos, int width, int height);

    /*!
     * @brief Event handler, detect when game is running or not
     * @fn void handleEvents();
     */
    void handleEvents();

    /*!
     * @brief Update the game, player or enemy position, collision etc.
     * @fn void update();
     */
    void update();

    /*!
     * @brief Return status of the game window if is running or not
     * @return isRunning;
     */
    bool running() { return isRunning; }

    /*!
     * @brief Render all objects in window after update
     * @fn void render();
     */
    void render();

    /*!
     * @brief Close the window and MinGL
     * @fn void clean();
     */
    void clean();

private:
    /*!
     * @brief isRunning : Status of the Game
     */
    bool isRunning;

    /*!
     * @brief isMainMenu : Status if the main menu window
     */
    bool isMainMenu;

    /*!
     * @brief isGameWon : Status of the game won window
     */
    bool isGameWon;

    /*!
     * @brief isGameLost : Status of the game lost window
     */
    bool isGameLost;

    /*!
     * @brief isResetGameLevel : Status of the reset game level
     */
    bool isResetGameLevel;

    /*!
     * @brief window : Game window
     */
    MinGL *window;

    /*!
     * @brief player : Player object
     */
    GameObject* player;

    /*!
     * @brief levelMap : Level map
     */
    Map* levelMap;

    /*!
     * @brief wallColliders : Vector of walls pointers
     */
    vector<unique_ptr<GameObject>> wallColliders;

    /*!
     * @brief pointColliders : Vector of points pointers
     */
    vector<unique_ptr<GameObject>> pointColliders;

    /*!
     * @brief invisibleHitBoxColliders : Vector of invisible hit box pointers
     */
    vector<unique_ptr<GameObject>> invisibleHitBoxColliders;

    /*!
     * @brief enemyColliders : Vector of enemy pointers
     */
    vector<unique_ptr<GameObject>> enemyColliders;

    /*!
     * @brief scoreText : Text containing player score
     */
    Text* scoreText;

    /*!
     * @brief livesText : Text containing player lives
     */
    Text* livesText;

    /*!
     * @brief mainMenuBackground : Main menu background
     */
    GameObject* mainMenuBackground;

    /*!
     * @brief wonMenuBackground : Won menu background
     */
    GameObject* wonMenuBackground;

    /*!
     * @brief lostMenuBackground : Lost menu background
     */
    GameObject* lostMenuBackground;

    /*!
     * @brief selector : Menu selector (red arrow)
     */
    GameObject* selector;

    /*!
     * @brief selectorCount : Selector counter for menu handling
     */
    unsigned selectorCount;

    /*!
     * @brief debugGameWonText : In Game won menu text for debug
     */
    Text* debugGameWonText;

    /*!
     * @brief debugGameLostText : In Game lost menu text for debug
     */
    Text* debugGameLostText;

    /*!
     * @brief debugGameMainMenuText : In Game main menu text for debug
     */
    Text* debugGameMainMenuText;

    /*!
     * @brief uIRect : In Game UI where lives and score are displayed
     */
    nsShape::Rectangle* uIRect;

    /*!
     * @brief keyboardCfg : Struct containing keyboard bindings
     */
    struct keyboardCfg {
        char keyUp; /**< keyUp : Keyboard up binding */
        char keyLeft; /**< keyLeft : Keyboard left binding */
        char keyDown; /**< keyDown : Keyboard down binding */
        char keyRight; /**< keyRight : Keyboard right binding */
        char keySelect; /**< keySelect : Keyboard select binding */
    } keyboardCfg;

};


#endif
