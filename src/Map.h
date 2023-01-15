/*!
 * @file Map.h
 * @brief Map Class
 */

#ifndef PACMAN_MINGL_MAP_H
#define PACMAN_MINGL_MAP_H

#include "mingl/gui/sprite.h"
#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"
#include "GameObject.h"
#include "ConfigManager.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;

/*!
 * @brief Map Class
 */
class Map {

public:
    /*!
     * @brief Constructor of Map Class
     * @fn Map();
     */
    Map();

    /*!
     * @brief Destructor of Map Class
     * @fn ~Map();
     */
    ~Map();

    /*!
     * @brief Level map loader
     * @param window
     * @param gameColliders
     * @param pointColliders
     * @param invisibleHitBoxColliders
     * @param enemyColliders
     * @fn void loadMap(MinGL* window, vector<unique_ptr<GameObject>>& gameColliders,
     *           vector<unique_ptr<GameObject>>& pointColliders,
     *           vector<unique_ptr<GameObject>>& invisibleHitBoxColliders,
     *           vector<unique_ptr<GameObject>>& enemyColliders);
     */
    void loadMap(MinGL* window, vector<unique_ptr<GameObject>>& gameColliders,
                 vector<unique_ptr<GameObject>>& pointColliders,
                 vector<unique_ptr<GameObject>>& invisibleHitBoxColliders,
                 vector<unique_ptr<GameObject>>& enemyColliders);

    /*!
     * @brief Initialize level map
     * @param levelMap
     * @fn void initMap(ConfigManager& levelMap);
     */
    void initMap(ConfigManager& levelMap);

private:
    /*!
     * @brief wall : game object wall
     */
    GameObject* wall;

    /*!
     * @brief point : game object point
     */
    GameObject* point;

    /*!
     * @brief invHitBox : game object invisible hit box
     */
    GameObject* invHitBox;

    /*!
     * @brief enemy : game object enemy
     */
    GameObject* enemy;

    /*!
     * @brief levelMap : Map data for generation
     */
    vector<vector<unsigned>> levelMap;

};


#endif
