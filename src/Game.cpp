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
    test = new nsShape::Rectangle(Vec2D(0, 0), Vec2D(140, 30), KBlack);
    scoreText = new Text(Vec2D(10, 20), "Score: 0", KWhite, GlutFont::BITMAP_HELVETICA_18);
    levelMap = new Map();

    levelMap->LoadMap(window, wallColliders, pointColliders, invisibleHitBoxColliders, enemyColliders);

    for (auto& c : enemyColliders) {
        c->setObjectDirection(1);
        c->setMovementSpeed(4);
    }
}

void Game::handleEvents() {
    if (window->isOpen() == 0) isRunning = false;
}

void Game::update() {
    player->setTempPosition();
    for (auto& c : enemyColliders) {
        c->setTempPosition();
        c->Update();
        c->Move(false);
    }

    player->Update();
//    for (auto& c : enemyColliders) c->Update();


    player->Move(true);
//    for (auto& c : enemyColliders) c->Move(false);

    for (auto& c : wallColliders) {
        if (Collision::AABB(player->getPos(), c->getPos(), 40, 40)) {
            player->setPos(player->getTempPosition().getX(), player->getTempPosition().getY());
            player->resetObjectDirection();
        }
        for (auto& cc : enemyColliders) {
            if (Collision::AABB(cc->getPos(), c->getPos(), 40, 40)) {
                cc->setPos(cc->getTempPosition().getX(), cc->getTempPosition().getY());
                cc->resetObjectDirection();
                cc->setObjectDirection(std::rand() % 4 + 1);
            }
        }
    }
    for (auto& c : invisibleHitBoxColliders) {
        if (Collision::AABB(player->getPos(), c->getPos(), 1, 1)) {
            player->resetObjectDirection();
        }
        for (auto& cc : enemyColliders) {
            if (Collision::AABB(cc->getPos(), c->getPos(), 1, 1)) {
                cc->resetObjectDirection();
                cc->setObjectDirection(std::rand() % 4 + 1);
            }
        }
    }
    for (auto& c : pointColliders) {
        if (Collision::AABB(player->getPos(), c->getPos(), 20, 20)) {
            if (!c->isInvisible()) player->addScore();
            c->setInvisible();
            scoreText->setContent("Score: " + to_string(player->getScore()));
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

    *window << *test;
    *window << *scoreText;
    player->Render();

    window->finishFrame();
    window->getEventManager().clearEvents();
}

void Game::clean() {
    window->stopGraphic();
}
