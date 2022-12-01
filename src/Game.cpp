#include "Game.h"


Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height) {
    window = new MinGL(title, nsGraphics::Vec2D(width, height), nsGraphics::Vec2D(xpos, ypos), nsGraphics::KBlack);
    window->initGlut();
    window->initGraphic();
    isRunning = true;
}

void Game::handleEvents() {
    if (window->isOpen() == 0) isRunning = false;
}

void Game::update() {

}

void Game::render() {
    window->clearScreen();

    if (window->isPressed({ 'w', false })) moveY-=5;
    if (window->isPressed({ 'a', false })) moveX-=5;
    if (window->isPressed({ 's', false })) moveY+=5;
    if (window->isPressed({ 'd', false })) moveX+=5;

    if (testX+moveX > 840-150) moveX-=5;
    if (testX+moveX < 0+150) moveX+=5;
    if (testY+moveY > 640-150) moveY-=5;
    if (testY+moveY < 0+150) moveY+=5;
    cout << testX << " " << moveX << " " << testX+moveX << endl;
    cout << testY << " " << moveY << " " << testY+moveY << endl;

    *window << Circle(Vec2D(testX+moveX,testY+moveY), 150, KYellow);
    *window << Circle(Vec2D(testX+moveX,250+moveY), 10, KBlack);
    *window << Triangle(Vec2D(testX+moveX,testY+moveY), Vec2D(triOne2X+moveX,triOne2Y+moveY), Vec2D(443+moveX,254+moveY), KBlack);
    *window << Triangle(Vec2D(testX+moveX,testY+moveY), Vec2D(triTwo2X+moveX,triTwo2Y+moveY), Vec2D(450+moveX,300+moveY), KBlack);
    *window << Triangle(Vec2D(testX+moveX,testY+moveY), Vec2D(triThree3X+moveX,triThree3Y+moveY), Vec2D(450+moveX,300+moveY), KBlack);
    *window << Triangle(Vec2D(testX+moveX,testY+moveY), Vec2D(triFourth3X+moveX,triFourth3Y+moveY), Vec2D(443+moveX,346+moveY), KBlack);



    if (triOneF) {
        triOne2X += 1;
        triOne2Y += 2;
        triFourth3X += 1;
        triFourth3Y -= 2;
        if (triOne2X == 443) {
            triOneF = false;
            triTwoF = true;
        }
    } else if (triOneB) {
        triOne2X -= 1;
        triOne2Y -= 2;
        triFourth3X -= 1;
        triFourth3Y += 2;
        if (triOne2X == 422 && triOne2Y == 212) {
            triOneB = false;
            triOneF = true;
        }
    } else if (triTwoF) {
        if (triTwo2X != 450) {
            triTwo2X += 1;
            triThree3X += 1;
        }
        triTwo2Y += 3;
        triThree3Y -= 3;
        if (triTwo2Y > 300) {
            triTwoF = false;
            triTwoB = true;
        }
    } else if (triTwoB) {
        if (triTwo2X != 443 && triTwo2Y <= 275) {
            triTwo2X -= 1;
            triThree3X -= 1;
        }
        triTwo2Y -= 3;
        triThree3Y += 3;
        if (triTwo2Y == 254) {
            triTwoB = false;
            triOneB = true;
        }
    }

    window->finishFrame();
    window->getEventManager().clearEvents();
}

void Game::clean() {
    window->stopGraphic();
}
