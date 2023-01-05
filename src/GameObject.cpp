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

    if (window->isPressed({'w', false}))
        yPos = spritePos.getY() - 5;
    if (window->isPressed({'s', false}))
        yPos = spritePos.getY() + 5;
    if (window->isPressed({'a', false}))
        xPos = spritePos.getX() - 5;
    if (window->isPressed({'d', false}))
        xPos = spritePos.getX() + 5;
}

Vec2D GameObject::getPos() {
    return sprite->getPosition();
}

void GameObject::setPos(const int x, const int y) {
    xPos = x;
    yPos = y;
}
