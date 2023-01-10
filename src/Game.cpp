#include "Game.h"
#include <thread>


Game::Game() {}

Game::~Game() {}

void Game::init(const string &title, int xPos, int yPos, int width, int height) {
    window = new MinGL(title, Vec2D(width, height), Vec2D(xPos, yPos), KBlack);
    window->initGlut();
    window->initGraphic();
    isRunning = true;
    isMainMenu = true;
    isGameWon = false;
    isGameLost = false;
    selectorCount = 0;
    selectorTimer = 150;
    isResetGameLevel = false;

    player = new GameObject("../assets/pacmanSkin.si2", window, 10 * 40, 14 * 40);
    scoreRect = new nsShape::Rectangle(Vec2D(0, 0), Vec2D(140, 30), KBlack);
    scoreText = new Text(Vec2D(10, 20), "Score: 0", KWhite, GlutFont::BITMAP_HELVETICA_18);
    mainMenuBackground = new GameObject("../assets/mainMenu.si2", window, 0, 0);
    selector = new GameObject("../assets/selector20x20.si2", window, 300, 260);
    debugGameLostText = new Text(Vec2D(10, 20), "Lost Screen", KWhite, GlutFont::BITMAP_HELVETICA_18);
    debugGameWonText = new Text(Vec2D(10, 20), "Won Screen", KWhite, GlutFont::BITMAP_HELVETICA_18);
    debugGameMainMenuText = new Text(Vec2D(10, 20), "Main Menu Screen", KWhite, GlutFont::BITMAP_HELVETICA_18);
    levelMap = new Map();

    levelMap->LoadMap(window, wallColliders, pointColliders, invisibleHitBoxColliders, enemyColliders);

    for (auto& enemy : enemyColliders) {
        enemy->setObjectDirection(1);
        enemy->setMovementSpeed(4);
    }
}

void Game::handleEvents() {
    if (window->isOpen() == 0) isRunning = false;
    if (isMainMenu) {

    } else if (isGameWon) {
        if (window->isPressed({'m', false})) {
            isGameWon = false;
            isMainMenu = true;
            isResetGameLevel = true;
            debugGameMainMenuText->setContent("Main Menu Screen");
        }
    } else if (isGameLost) {
        if (window->isPressed({'m', false})) {
            isGameLost = false;
            isMainMenu = true;
            isResetGameLevel = true;
            debugGameMainMenuText->setContent("Main Menu Screen");
        }
    }
}

void Game::update() {
    if (isMainMenu) {
        switch (selectorCount) {
            case 0:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(290, 300);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'w', false})) {
                    selectorCount = 5;
                    selector->setPos(310, 500);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'e', false})) {
                    isMainMenu = false;
                    if (isResetGameLevel) {
                        for (auto& enemy : enemyColliders) enemy->resetPosition();
                        for (auto& point : pointColliders) point->setVisible();
                        player->resetPosition();
                        player->reviveObject();
                        player->resetScore();
                        scoreText->setContent("Score: " + to_string(player->getScore()));
                        isResetGameLevel = false;
                    }
                    this_thread::sleep_for(chrono::milliseconds(500));
                }
                break;
            case 1:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(160, 340);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(300, 260);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'e', false})) {
                    debugGameMainMenuText->setContent("Main Menu Screen + LEVELS WIP");
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                }
                break;
            case 2:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(230, 380);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(290, 300);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'e', false})) {
                    debugGameMainMenuText->setContent("Main Menu Screen + CUSTOM DIFFICULTY WIP");
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                }
                break;
            case 3:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(300, 420);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(160, 340);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'e', false})) {
                    debugGameMainMenuText->setContent("Main Menu Screen + MULTIPLAYER WIP");
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                }
                break;
            case 4:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(310, 500);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(230, 380);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'e', false})) {
                    debugGameMainMenuText->setContent("Main Menu Screen + SCORES WIP");
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                }
                break;
            case 5:
                if (window->isPressed({'s', false})) {
                    selectorCount = 0;
                    selector->setPos(300, 260);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(300, 420);
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                } else if (window->isPressed({'e', false})) {
                    isRunning = false;
                    this_thread::sleep_for(chrono::milliseconds(selectorTimer));
                }
                break;
            default:
                break;
        }
        selector->Update();
    } else if (isGameWon) {

    } else if (isGameLost) {

    } else {
        player->setTempPosition();
        for (auto& enemy : enemyColliders) {
            enemy->setTempPosition();
            enemy->Update();
            enemy->Move(false);
        }

        player->Update();
//    for (auto& c : enemyColliders) c->Update();


        player->Move(true);
//    for (auto& c : enemyColliders) c->Move(false);

        // Collision
        for (auto& wall : wallColliders) {
            // wall and player
            if (Collision::AABB(player->getPos(), wall->getPos(), 40, 40)) {
                player->setPos(player->getTempPosition().getX(), player->getTempPosition().getY());
                player->resetObjectDirection();
            }
            // wall and enemy
            for (auto& enemy : enemyColliders) {
                if (Collision::AABB(enemy->getPos(), wall->getPos(), 40, 40)) {
                    enemy->setPos(enemy->getTempPosition().getX(), enemy->getTempPosition().getY());
                    enemy->resetObjectDirection();
                    enemy->setObjectDirection(std::rand() % 4 + 1);
                }
            }
        }
        for (auto& invHitVox : invisibleHitBoxColliders) {
            // invisibleHitBox and player
            if (Collision::AABB(player->getPos(), invHitVox->getPos(), 1, 1)) {
                player->resetObjectDirection();
            }
            // invisibleHitBox and enemy
            for (auto& enemy : enemyColliders) {
                if (Collision::AABB(enemy->getPos(), invHitVox->getPos(), 1, 1)) {
                    enemy->resetObjectDirection();
                    enemy->setObjectDirection(std::rand() % 4 + 1);
                }
            }
        }
        for (auto& scorePoint : pointColliders) {
            // point and player
            if (Collision::AABB(player->getPos(), scorePoint->getPos(), 20, 20)) {
                if (!scorePoint->isInvisible()) player->addScore();
                scorePoint->setInvisible();
                scoreText->setContent("Score: " + to_string(player->getScore()));
                if (player->getScore() == pointColliders.size() * 100) isGameWon = true;
            }
        }
        for (auto& enemy : enemyColliders) {
            // enemy and player
            if (Collision::AABB(player->getPos(), enemy->getPos(), 40, 40)) {
                player->killObject();
                isGameLost = true;
            }
        }
    }
}

void Game::render() {
    window->clearScreen();

    if (isMainMenu) {
        mainMenuBackground->Render();
        selector->Render();
        *window << *debugGameMainMenuText;
    } else if (isGameWon) {
        *window << *debugGameWonText;
    } else if (isGameLost) {
        *window << *debugGameLostText;
    } else {
        for (auto& wall : wallColliders) wall->Render();
        for (auto& scorePoint : pointColliders) scorePoint->Render();
        for (auto& invHitBox : invisibleHitBoxColliders) invHitBox->Render();
        for (auto& enemy : enemyColliders) enemy->Render();

        *window << *scoreRect;
        *window << *scoreText;
        player->Render();
    }

    window->finishFrame();
    window->getEventManager().clearEvents();
}

void Game::clean() {
    window->stopGraphic();
}
