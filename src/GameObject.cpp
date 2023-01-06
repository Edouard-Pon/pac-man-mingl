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
    if (!objectProperty.invisible && !objectProperty.dead) *window << *sprite;
}

void GameObject::Move(const bool isPlayer) {
    Vec2D spritePos = sprite->getPosition();

    if (isPlayer) {
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
    }

    if (objectProperty.up) yPos = spritePos.getY() - objectProperty.movementSpeed;
    if (objectProperty.down) yPos = spritePos.getY() + objectProperty.movementSpeed;
    if (objectProperty.left) xPos = spritePos.getX() - objectProperty.movementSpeed;
    if (objectProperty.right) xPos = spritePos.getX() + objectProperty.movementSpeed;
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

void GameObject::killObject() {
    objectProperty.dead = true;
}

void GameObject::addScore() {
    objectProperty.score += 100;
}

bool GameObject::isInvisible() const {
    return objectProperty.invisible;
}

unsigned GameObject::getScore() const {
    return objectProperty.score;
}

void GameObject::setObjectDirection(const unsigned direction) {
    switch (direction) {
        case 1:
            objectProperty.up = true;
            break;
        case 2:
            objectProperty.down = true;
            break;
        case 3:
            objectProperty.right = true;
            break;
        case 4:
            objectProperty.left = true;
            break;
        default:
            break;
    }
}

void GameObject::setTempPosition() {
    tempPosition = { xPos, yPos };
}

Vec2D GameObject::getTempPosition() {
    return tempPosition;
}

void GameObject::setMovementSpeed(int speed) {
    objectProperty.movementSpeed = speed;
}
