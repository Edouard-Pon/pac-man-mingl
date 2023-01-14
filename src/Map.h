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


class Map {

public:
    Map();
    ~Map();

    void loadMap(MinGL* window, vector<unique_ptr<GameObject>>& gameColliders,
                 vector<unique_ptr<GameObject>>& pointColliders,
                 vector<unique_ptr<GameObject>>& invisibleHitBoxColliders,
                 vector<unique_ptr<GameObject>>& enemyColliders);
    void initMap(ConfigManager& levelMap);

private:
    GameObject* wall;
    GameObject* point;
    GameObject* invHitBox;
    GameObject* enemy;

    //  For Test; Changing Soon;
    vector<vector<unsigned>> levelMap;

};


#endif
