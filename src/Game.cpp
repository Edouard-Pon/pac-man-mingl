#include "Game.h"

using namespace std;


Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
    window = new MinGL(title, nsGraphics::Vec2D(width, height), nsGraphics::Vec2D(xpos, ypos), nsGraphics::KBlack);
    window->initGlut();
    window->initGraphic();
    isRunning = true;
}

void Game::handleEvents() {
    if (!window->isOpen()) isRunning = false;
}

void Game::update() {

}

void Game::render() {
    window->clearScreen();
    window->getEventManager().clearEvents();

    window->finishFrame();
}

void Game::clean() {
    window->stopGraphic();
}
