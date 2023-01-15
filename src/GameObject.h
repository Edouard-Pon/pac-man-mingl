/*!
 * @file GameObject.h
 */

#ifndef PACMAN_MINGL_GAMEOBJECT_H
#define PACMAN_MINGL_GAMEOBJECT_H

#include <iostream>
#include <thread>
#include "mingl/gui/sprite.h"
#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"
#include "ConfigManager.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;

/*!
 * @brief GameObject Class
 */
class GameObject {

public:
    /*!
     * @brief Constructor for GameObject Class
     * @param fileName
     * @param win
     * @param x
     * @param y
     * @fn GameObject(const string &fileName, MinGL* win, int x, int y);
     */
    GameObject(const string &fileName, MinGL* win, int x, int y);

    /*!
     * @brief Destructor for GameObject Class
     * @fn ~GameObject();
     */
    ~GameObject();

    /*!
     * @brief Update the game object position
     * @fn void Update();
     */
    void Update();

    /*!
     * @brief Render the game object (add object to window)
     * @fn void Render();
     */
    void Render();

    /*!
     * @brief Move the game object
     * @param isPlayer
     * @fn void Move(bool isPlayer);
     */
    void Move(bool isPlayer);

    /*!
     * @brief Return current object position in Vec2D containing x and y
     * @return Vec2D(xPos, yPos);
     */
    Vec2D getPos();

    /*!
     * @brief Set new position for game object with x and y
     * @param x
     * @param y
     * @fn void setPos(int x, int y);
     */
    void setPos(int x, int y);

    /*!
     * @brief Reset all 4 object directions to false (objectProperty.up = false; etc)
     * @fn void resetObjectDirection();
     */
    void resetObjectDirection();

    /*!
     * @brief Set game object invisible
     * @fn void setInvisible();
     */
    void setInvisible();

    /*!
     * @brief Set game object visible
     * @fn void setVisible();
     */
    void setVisible();

    /*!
     * @brief Kill the game object
     * @fn void killObject();
     */
    void killObject();

    /*!
     * @brief Add score to game object (+100)
     * @fn void addScore();
     */
    void addScore();

    /*!
     * @brief Return if the game object is Invisible or not
     * @return objectProperty.invisible;
     */
    bool isInvisible() const;

    /*!
     * @brief Return game object score
     * @return objectProperty.score;
     */
    unsigned getScore() const;

    /*!
     * @brief Set object direction (up (1), down (2), left (4) or right (3)) depends of direction parameter
     * @param direction
     * @fn void setObjectDirection(unsigned direction);
     */
    void setObjectDirection(unsigned direction);

    /*!
     * @brief Set temporary position of game object
     * @fn void setTempPosition();
     */
    void setTempPosition();

    /*!
     * @brief Return temporary position created previously
     * @return tempPosition;
     */
    Vec2D getTempPosition();

    /*!
     * @brief Set movement speed to game object
     * @param speed
     * @fn void setMovementSpeed(int speed);
     */
    void setMovementSpeed(int speed);

    /*!
     * @brief Reset game object position to initial (start of the game)
     * @fn void resetPosition();
     */
    void resetPosition();

    /*!
     * @brief Revive the game object
     * @fn void reviveObject();
     */
    void reviveObject();

    /*!
     * @brief Reset game object score to 0
     * @fn void resetScore();
     */
    void resetScore();

    /*!
     * @brief Set number of lives to game object
     * @param lives
     * @fn void setLives(unsigned lives);
     */
    void setLives(unsigned lives);

    /*!
     * @brief Return number of game object lives
     * @return objectProperty.lives;
     */
    unsigned getLives() const;

    /*!
     * @brief Set game object Invincible or not
     * @param isInvincible
     * @fn void setInvincible(bool isInvincible);
     */
    void setInvincible(bool isInvincible);

    /*!
     * @brief Return if the game object is Invincible or not
     * @return objectProperty.invincible;
     */
    bool isInvincible() const;

    /*!
     * @brief Initialize timer for game object
     * @fn void setTimer();
     */
    void setTimer();

    /*!
     * @brief Return timer in seconds
     * @return time;
     */
    unsigned getTimer();

    /*!
     * @brief Return invisible animation counter
     * @return invAnimation;
     */
    unsigned getInvAnimation() const;

    /*!
     * @brief Set invisible animation counter
     * @param currentTimer
     * @fn void setInvAnimation(unsigned currentTimer);
     */
    void setInvAnimation(unsigned currentTimer);

    /*!
     * @brief Initialize keyboard config
     * @param cfg
     * @fn void initKeyboardConfig(ConfigManager* cfg);
     */
    void initKeyboardConfig(ConfigManager* cfg);

private:
    /*!
     * @brief xPos : x game object position
     */
    int xPos;

    /*!
     * @brief yPos : y game object position
     */
    int yPos;

    /*!
     * @brief xInitialPosition : x initial game object position (x spawn point)
     */
    int xInitialPosition;

    /*!
     * @brief yInitialPosition : y initial game object position (y spawn point)
     */
    int yInitialPosition;

    /*!
     * @brief tempPosition : temporary game object position
     */
    Vec2D tempPosition;

    /*!
     * @brief timer : game object timer
     */
    chrono::time_point<chrono::steady_clock> timer;

    /*!
     * @brief invAnimation : invisible game object animation counter
     */
    unsigned invAnimation = 0;

    /*!
     * @brief objectProperty : Game object property
     */
    struct objectProperty {
        bool up = false; /**< up : game object direction */
        bool down = false; /**< down : game object direction */
        bool right = false; /**< right : game object direction */
        bool left = false; /**< left : game object direction */
        bool invisible = false; /**< invisible : game object invisible status */
        bool dead = false; /**< dead : game object dead status */
        unsigned score = 0; /**< score : game object score */
        int movementSpeed = 5; /**< movementSpeed : game object movement speed */
        unsigned lives = 3; /**< lives : game object lives */
        bool invincible = false; /**< invincible : game object invincible status */
    } objectProperty;

    /*!
     * @brief keyboardSettings : Game object keyboard settings
     */
    struct keyboardSettings {
        char up; /**< up : keyboard up binding */
        char left; /**< left : keyboard left binding */
        char down; /**< down : keyboard down binding */
        char right; /**< right : keyboard right binding */
    } keyboardSettings;

    /*!
     * @brief sprite : game object sprite
     */
    Sprite* sprite;

    /*!
     * @brief window : game window
     */
    MinGL* window;

};


#endif
