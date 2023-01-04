#include "Game.h"
#include "GameObject.h"


GameObject* player;
GameObject* enemy;

Game::Game() {}

Game::~Game() {}

void Game::init(const string &title, int xPos, int yPos, int width, int height) {
    window = new MinGL(title, Vec2D(width, height), Vec2D(xPos, yPos), KBlack);
    window->initGlut();
    window->initGraphic();
    isRunning = true;

    player = new GameObject("../assets/pacman.si2", window, 0, 0);
    enemy = new GameObject("../assets/phantom.si2", window, 100, 100);
}

void Game::handleEvents() {
    if (window->isOpen() == 0) isRunning = false;
}

void Game::update() {
    player->Update();
    enemy->Update();
}

void Game::render() {
    window->clearScreen();

    player->Render();
    enemy->Render();

    window->finishFrame();
    window->getEventManager().clearEvents();
}

void Game::clean() {
    window->stopGraphic();
}
