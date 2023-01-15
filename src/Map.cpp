/*!
 * @file Map.cpp
 * @brief Map Class
 */

#include "Map.h"


Map::Map() {}

Map::~Map() {}

void Map::loadMap(MinGL* window, vector<unique_ptr<GameObject>>& wallColliders,
                  vector<unique_ptr<GameObject>>& pointColliders,
                  vector<unique_ptr<GameObject>>& invisibleHitBoxColliders,
                  vector<unique_ptr<GameObject>>& enemyColliders) {
    unsigned type = 0;

    for (unsigned row = 0; row < 16; ++row) {
        for (unsigned column = 0; column < 21; ++column) {
            type = levelMap[row][column];

            switch (type) {
                case 1:
                    wall = new GameObject("../assets/wall.si2", window, column * 40, row * 40);
                    wallColliders.emplace_back(wall);
                    break;
                case 2:
                    point = new GameObject("../assets/point.si2", window, column * 40, row * 40);
                    pointColliders.emplace_back(point);
                    break;
                case 3:
                    invHitBox = new GameObject("../assets/invisibleHitBox.si2", window, column * 40, row * 40);
                    invisibleHitBoxColliders.emplace_back(invHitBox);
                    break;
                case 4:
                    enemy = new GameObject("../assets/phantomRed.si2", window, column * 40, row * 40);
                    enemyColliders.emplace_back(enemy);
                    break;
                case 5:
                    enemy = new GameObject("../assets/phantomYellow.si2", window, column * 40, row * 40);
                    enemyColliders.emplace_back(enemy);
                    break;
                case 6:
                    enemy = new GameObject("../assets/phantomRose.si2", window, column * 40, row * 40);
                    enemyColliders.emplace_back(enemy);
                    break;
                case 7:
                    enemy = new GameObject("../assets/phantomCyan.si2", window, column * 40, row * 40);
                    enemyColliders.emplace_back(enemy);
                    break;
                case 8:
                    enemy = new GameObject("../assets/phantomGreen.si2", window, column * 40, row * 40);
                    enemyColliders.emplace_back(enemy);
                    break;
                default:
                    break;
            }
        }
    }
}

void Map::initMap(ConfigManager &levelMapData) {
    levelMap = levelMapData.getLevelData();
}
