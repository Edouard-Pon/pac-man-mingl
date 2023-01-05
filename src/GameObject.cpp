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
    if (!objectProperty.invisible) *window << *sprite;
}

void GameObject::Move() {
    Vec2D spritePos = sprite->getPosition();

    if (window->isPressed({'w', false})) {
        resetObjectDirection();
        objectProperty.up = true;
    }
    if (window->isPressed({'s', false})) {
        resetObjectDirection();
        objectProperty.down = true;
    }
    if (window->isPressed({'a', false})) {
        resetObjectDirection();
        objectProperty.left = true;
    }
    if (window->isPressed({'d', false})) {
        resetObjectDirection();
        objectProperty.right = true;
    }

    if (objectProperty.up) yPos = spritePos.getY() - 5;
    if (objectProperty.down) yPos = spritePos.getY() + 5;
    if (objectProperty.left) xPos = spritePos.getX() - 5;
    if (objectProperty.right) xPos = spritePos.getX() + 5;
}

Vec2D GameObject::getPos() {
    return Vec2D(xPos, yPos);
}

void GameObject::setPos(const int x, const int y) {
    xPos = x;
    yPos = y;
}

void GameObject::resetObjectDirection() {
    objectProperty.up = false;
    objectProperty.down = false;
    objectProperty.right = false;
    objectProperty.left = false;
}

void GameObject::setInvisible() {
    objectProperty.invisible = true;
}
