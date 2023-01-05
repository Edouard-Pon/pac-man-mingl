#include "Game.h"
#include "Collision.h"


Game::Game() {}

Game::~Game() {}

void Game::init(const string &title, int xPos, int yPos, int width, int height) {
    window = new MinGL(title, Vec2D(width, height), Vec2D(xPos, yPos), KBlack);
    window->initGlut();
    window->initGraphic();
    isRunning = true;

    player = new GameObject("../assets/pacman.si2", window, 40, 40);
    enemy = new GameObject("../assets/phantom.si2", window, 80, 40);
    levelMap = new Map();

    levelMap->LoadMap(window,gameColliders);
}

void Game::handleEvents() {
    if (window->isOpen() == 0) isRunning = false;
}

void Game::update() {
    Vec2D tmp = player->getPos();
    cout << "tmp: " << tmp << endl;

    player->Update();
    enemy->Update();

    player->Move();
    for (auto& c : gameColliders) {
        if (Collision::AABB(player->getPos(), c->getPos(), 40, 40)) {
            cout << "Collision Detected" << endl;
            cout << "P: " << player->getPos() << endl;
            cout << "W: " << c->getPos() << endl;
            player->setPos(tmp.getX(), tmp.getY());
        }
    }
}

void Game::render() {
    window->clearScreen();

    for (auto& c : gameColliders) c->Render();

    player->Render();
    enemy->Render();

    window->finishFrame();
    window->getEventManager().clearEvents();
}

void Game::clean() {
    window->stopGraphic();
}
