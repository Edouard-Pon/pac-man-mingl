#include "GameObject.h"
#include "SpriteManager.h"


GameObject::GameObject(const string &fileName, MinGL* win, int x, int y) {
    window = win;
    sprite = SpriteManager::LoadSprite(fileName, Vec2D(x, y));

    xPos = x;
    yPos = y;
}

GameObject::~GameObject() {}

void GameObject::Update() {
    ++xPos;
    ++yPos;

    sprite->setPosition(Vec2D(xPos, yPos));
}

void GameObject::Render() {
//    sprite->draw(*window);
    *window << *sprite;
}
