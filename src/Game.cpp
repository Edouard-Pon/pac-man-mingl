#include "Game.h"
#include "Collision.h"


Game::Game() {}

Game::~Game() {}

void Game::init(const string &title, int xPos, int yPos, int width, int height) {
    window = new MinGL(title, Vec2D(width, height), Vec2D(xPos, yPos), KBlack);
    window->initGlut();
    window->initGraphic();
    isRunning = true;

    player = new GameObject("../assets/pacman.si2", window, 10 * 40, 14 * 40);
//    enemy = new GameObject("../assets/phantom.si2", window, 10 * 40, 9 * 40);
    levelMap = new Map();

    levelMap->LoadMap(window, wallColliders, pointColliders, invisibleHitBoxColliders, enemyColliders);
}

void Game::handleEvents() {
    if (window->isOpen() == 0) isRunning = false;
}

void Game::update() {
    Vec2D tmp = player->getPos();

    player->Update();
//    enemy->Update();

    player->Move();
    for (auto& c : wallColliders) {
        if (Collision::AABB(player->getPos(), c->getPos(), 40, 40)) {
            player->setPos(tmp.getX(), tmp.getY());
            player->resetObjectDirection();
        }
    }
    for (auto& c : invisibleHitBoxColliders) {
        if (Collision::AABB(player->getPos(), c->getPos(), 1, 1)) {
            player->resetObjectDirection();
        }
    }
    for (auto& c : pointColliders) {
        if (Collision::AABB(player->getPos(), c->getPos(), 20, 20)) {
            if (!c->isInvisible()) player->addScore();
            c->setInvisible();
            cout << "Score: " << player->getScore() << endl;
        }
    }
    for (auto& c : enemyColliders) {
        if (Collision::AABB(player->getPos(), c->getPos(), 40, 40)) {
            player->killObject();
        }
    }
}

void Game::render() {
    window->clearScreen();

    for (auto& c : wallColliders) c->Render();
    for (auto& c : pointColliders) c->Render();
    for (auto& c : invisibleHitBoxColliders) c->Render();
    for (auto& c : enemyColliders) c->Render();

    player->Render();
//    enemy->Render();

    window->finishFrame();
    window->getEventManager().clearEvents();
}

void Game::clean() {
    window->stopGraphic();
}
