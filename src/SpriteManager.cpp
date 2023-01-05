#include "SpriteManager.h"


Sprite *SpriteManager::LoadSprite(const string &fileName, const Vec2D& position) {
    Sprite* sprite = new Sprite(fileName, position);

    return sprite;
}

void SpriteManager::Draw(MinGL &window, Sprite *spr, Vec2D &coordinates) {
    spr->setPosition(coordinates);
    window << *spr;
}
