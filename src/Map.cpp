#include "Map.h"

// For Test; Changing Soon
int testMap[16][21] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,2,2,2,3,2,2,2,2,1,1,1,2,2,2,2,3,2,2,2,1},
        {1,2,1,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,1,2,1},
        {1,3,2,2,3,2,3,2,3,2,2,2,3,2,3,2,3,2,2,3,1},
        {1,2,1,1,2,1,2,1,1,1,1,1,1,1,2,1,2,1,1,2,1},
        {1,2,2,2,3,1,2,3,2,2,1,2,2,3,2,1,3,2,2,2,1},
        {1,1,1,1,2,1,1,2,1,2,1,2,1,2,1,1,2,1,1,1,1},
        {1,1,1,1,2,1,2,3,2,3,2,3,2,3,2,1,2,1,1,1,1},
        {1,2,2,2,3,2,3,1,1,0,1,0,1,1,3,2,3,2,2,2,1},
        {1,2,1,1,2,1,2,1,4,4,4,4,4,1,2,1,2,1,1,2,1},
        {1,2,2,2,3,1,2,1,0,1,1,1,0,1,2,1,3,2,2,2,1},
        {1,1,1,1,3,2,3,2,3,2,3,2,3,2,3,2,3,1,1,1,1},
        {1,2,2,2,3,1,1,1,2,1,2,1,2,1,1,1,3,2,2,2,1},
        {1,2,1,1,3,2,2,1,2,1,2,1,2,1,2,2,3,1,1,2,1},
        {1,2,2,2,2,1,2,2,3,2,3,2,3,2,2,1,2,2,2,2,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

Map::Map() {
    TestLoadMap(testMap);
}

Map::~Map() {}

void Map::TestLoadMap(int arr[16][21]) {
    for (unsigned row = 0; row < 16; ++row) {
        for (unsigned column = 0; column < 21; ++column) {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::LoadMap(MinGL* window, vector<unique_ptr<GameObject>>& wallColliders,
                  vector<unique_ptr<GameObject>>& pointColliders,
                  vector<unique_ptr<GameObject>>& invisibleHitBoxColliders,
                  vector<unique_ptr<GameObject>>& enemyColliders) {
    unsigned type = 0;

    for (unsigned row = 0; row < 16; ++row) {
        for (unsigned column = 0; column < 21; ++column) {
            type = map[row][column];

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
                    enemy = new GameObject("../assets/phantom.si2", window, column * 40, row * 40);
                    enemyColliders.emplace_back(enemy);
                    break;
                default:
                    break;
            }
        }
    }
}
