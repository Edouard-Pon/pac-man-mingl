#ifndef PACMAN_MINGL_MAP_H
#define PACMAN_MINGL_MAP_H

#include "mingl/gui/sprite.h"
#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"
#include "GameObject.h"

using namespace std;
using namespace nsGraphics;
using namespace nsGui;


class Map {

public:
    Map();
    ~Map();

    void TestLoadMap(int arr[16][21]);
    void LoadMap(MinGL* window, vector<unique_ptr<GameObject>>& gameColliders,
                 vector<unique_ptr<GameObject>>& pointColliders,
                 vector<unique_ptr<GameObject>>& invisibleHitBoxColliders);

private:
    GameObject* wall;
    GameObject* point;
    GameObject* invHitBox;

    //  For Test; Changing Soon;
    int map[20][25];

};


#endif
