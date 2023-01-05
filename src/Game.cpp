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
    wallTest = new GameObject("../assets/wall.si2", window, 600, 400);
    wallTest2 = new GameObject("../assets/wall.si2", window, 700, 400);
}

void Game::handleEvents() {
    if (window->isOpen() == 0) isRunning = false;
}

void Game::update() {
    Vec2D tmp = player->getPos();

    player->Update();
    enemy->Update();

    if (Collision::AABB(player->getPos(), wallTest->getPos(), 40, 40)) {
        cout << "Collision Detected" << endl;
        cout << "P: " << player->getPos() << endl;
        cout << "W: " << wallTest->getPos() << endl;
        player->setPos(tmp.getX(), tmp.getY());
    } else {
        player->Move();
    }

}

void Game::render() {
    window->clearScreen();

    player->Render();
    enemy->Render();
    wallTest->Render();
    wallTest2->Render();

    window->finishFrame();
    window->getEventManager().clearEvents();
}

void Game::clean() {
    window->stopGraphic();
}
