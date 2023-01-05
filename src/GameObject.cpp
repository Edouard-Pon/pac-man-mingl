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
    sprite->setPosition(Vec2D(xPos, yPos));
}

void GameObject::Render() {
//    sprite->draw(*window);
    *window << *sprite;
}

void GameObject::Move() {
    Vec2D spritePos = sprite->getPosition();

    if (window->isPressed({'w', false})) {
        resetObjectDirection();
        objectDirection.up = true;
    }
    if (window->isPressed({'s', false})) {
        resetObjectDirection();
        objectDirection.down = true;
    }
    if (window->isPressed({'a', false})) {
        resetObjectDirection();
        objectDirection.left = true;
    }
    if (window->isPressed({'d', false})) {
        resetObjectDirection();
        objectDirection.right = true;
    }

    if (objectDirection.up) yPos = spritePos.getY() - 5;
    if (objectDirection.down) yPos = spritePos.getY() + 5;
    if (objectDirection.left) xPos = spritePos.getX() - 5;
    if (objectDirection.right) xPos = spritePos.getX() + 5;
}

Vec2D GameObject::getPos() {
    return Vec2D(xPos, yPos);
}

void GameObject::setPos(const int x, const int y) {
    xPos = x;
    yPos = y;
}

void GameObject::resetObjectDirection() {
    objectDirection.up = false;
    objectDirection.down = false;
    objectDirection.right = false;
    objectDirection.left = false;
}
