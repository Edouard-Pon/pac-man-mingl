#include "Game.h"
#include <thread>
#include <cmath>


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
    isResetGameLevel = false;

    player = new GameObject("../assets/pacmanSkin.si2", window, 10 * 40, 14 * 40);
    scoreRect = new nsShape::Rectangle(Vec2D(0, 0), Vec2D(140, 30), KBlack);
    scoreText = new Text(Vec2D(10, 10), "Score: 0", KWhite, GlutFont::BITMAP_HELVETICA_18, Text::HorizontalAlignment::ALIGNH_LEFT, Text::VerticalAlignment::ALIGNV_CENTER);
    mainMenuBackground = new GameObject("../assets/mainMenu.si2", window, 0, 0);
    wonMenuBackground = new GameObject("../assets/wonMenu.si2", window, 0, 0);
    lostMenuBackground = new GameObject("../assets/lostMenu.si2", window, 0, 0);
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
    player->setLives(3);
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
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    selectorCount = 5;
                    selector->setPos(310, 500);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    isMainMenu = false;
                    if (isResetGameLevel) {
                        for (auto& enemy : enemyColliders) enemy->resetPosition();
                        for (auto& point : pointColliders) point->setVisible();
                        player->resetPosition();
                        player->reviveObject();
                        player->resetScore();
                        scoreText->setContent("Score: " + to_string(player->getScore()));
                        scoreText->setPosition({ 10, 20 });
                        scoreText->setTextColor(KWhite);
                        isResetGameLevel = false;
                    }
                    selectorCount = 0;
                    selector->setPos(300, 440);
                    KeyboardController::resetAllKeys(window);
                    this_thread::sleep_for(chrono::milliseconds(500));
                }
                break;
            case 1:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(160, 340);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(300, 260);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    debugGameMainMenuText->setContent("Main Menu Screen + LEVELS WIP");
                    KeyboardController::resetAllKeys(window);
                }
                break;
            case 2:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(230, 380);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(290, 300);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    debugGameMainMenuText->setContent("Main Menu Screen + CUSTOM DIFFICULTY WIP");
                    KeyboardController::resetAllKeys(window);
                }
                break;
            case 3:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(300, 420);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(160, 340);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    debugGameMainMenuText->setContent("Main Menu Screen + MULTIPLAYER WIP");
                    KeyboardController::resetAllKeys(window);
                }
                break;
            case 4:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(310, 500);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(230, 380);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    debugGameMainMenuText->setContent("Main Menu Screen + SCORES WIP");
                    KeyboardController::resetAllKeys(window);
                }
                break;
            case 5:
                if (window->isPressed({'s', false})) {
                    selectorCount = 0;
                    selector->setPos(300, 260);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(300, 420);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    isRunning = false;
                }
                break;
            default:
                break;
        }
        selector->Update();
    } else if (isGameWon) {
        switch (selectorCount) {
            case 0:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(310, 500);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    selectorCount = 1;
                    selector->setPos(310, 500);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    selector->setPos(300, 260);
                    isGameWon = false;
                    isMainMenu = true;
                    isResetGameLevel = true;
                    debugGameMainMenuText->setContent("Main Menu Screen");
                    KeyboardController::resetAllKeys(window);
                }
                break;
            case 1:
                if (window->isPressed({'s', false})) {
                    selectorCount = 0;
                    selector->setPos(300, 440);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(300, 440);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    isRunning = false;
                }
                break;
            default:
                break;
        }
        selector->Update();
    } else if (isGameLost) {
        switch (selectorCount) {
            case 0:
                if (window->isPressed({'s', false})) {
                    ++selectorCount;
                    selector->setPos(310, 500);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    selectorCount = 1;
                    selector->setPos(310, 500);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    selector->setPos(300, 260);
                    isGameLost = false;
                    isMainMenu = true;
                    isResetGameLevel = true;
                    debugGameMainMenuText->setContent("Main Menu Screen");
                    KeyboardController::resetAllKeys(window);
                }
                break;
            case 1:
                if (window->isPressed({'s', false})) {
                    selectorCount = 0;
                    selector->setPos(300, 440);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'w', false})) {
                    --selectorCount;
                    selector->setPos(300, 440);
                    KeyboardController::resetAllKeys(window);
                } else if (window->isPressed({'e', false})) {
                    isRunning = false;
                }
                break;
            default:
                break;
        }
        selector->Update();
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
            for (auto& enemy : enemyColliders) {
                // wall and enemy
                if (Collision::AABB(enemy->getPos(), wall->getPos(), 40, 40)) {
                    enemy->setPos(enemy->getTempPosition().getX(), enemy->getTempPosition().getY());
                    enemy->resetObjectDirection();
                    enemy->setObjectDirection(std::rand() % 4 + 1);
                }
                // enemy and player
                if (Collision::AABB(player->getPos(), enemy->getPos(), 40, 40)) {
                    if (player->getLives() == 0 && !player->isInvincible()) {
                        player->killObject();
                        isGameLost = true;
                        scoreText->setPosition({ 400, 286 });
                        scoreText->setTextColor(KYellow);
                        scoreText->setContent(to_string(player->getScore() * (player->getLives() + 1)));
                    } else if (!player->isInvincible()) {
                        player->setInvincible(true);
                        player->setLives(player->getLives() - 1);
                        player->setTimer();
                    }
                }
                for (auto& invHitVox : invisibleHitBoxColliders) {
                    // invisibleHitBox and player
                    if (Collision::AABB(player->getPos(), invHitVox->getPos(), 1, 1)) {
                        player->resetObjectDirection();
                    }
                    // invisibleHitBox and enemy
                    if (Collision::AABB(enemy->getPos(), invHitVox->getPos(), 1, 1)) {
                        enemy->resetObjectDirection();
                        enemy->setObjectDirection(std::rand() % 4 + 1);
                    }
                }
                if (player->isInvincible()) {
                    if (player->getTimer() > enemy->getInvAnimation()) {
                        enemy->setInvAnimation(player->getTimer());
                        if (enemy->isInvisible()) enemy->setVisible();
                        else enemy->setInvisible();
                    }
                    enemy->setMovementSpeed(2);
                }
            }
        }
        for (auto& scorePoint : pointColliders) {
            // point and player
            if (Collision::AABB(player->getPos(), scorePoint->getPos(), 20, 20)) {
                if (!scorePoint->isInvisible()) player->addScore();
                scorePoint->setInvisible();
                scoreText->setContent("Score: " + to_string(player->getScore()));
                if (player->getScore() == pointColliders.size() * 100) {
                    isGameWon = true;
                    scoreText->setPosition({ 400, 286 });
                    scoreText->setTextColor(KYellow);
                    scoreText->setContent(to_string(player->getScore()));
                }
            }
        }

        if (player->getTimer() >= 10) {
            player->setInvincible(false);
            for (auto& enemy : enemyColliders) {
                enemy->setVisible();
                enemy->setInvAnimation(0);
                enemy->setMovementSpeed(4);
            }
        }
        cout << "Undead Timer: " << player->getTimer() << endl;
//        cout << "Player Lives: " << player->getLives() << endl;
    }
}

void Game::render() {
    window->clearScreen();

    if (isMainMenu) {
        mainMenuBackground->Render();
        selector->Render();
        *window << *debugGameMainMenuText;
    } else if (isGameWon) {
        wonMenuBackground->Render();
        selector->Render();
        *window << *debugGameWonText;
        *window << *scoreText;
    } else if (isGameLost) {
        lostMenuBackground->Render();
        selector->Render();
        *window << *debugGameLostText;
        *window << *scoreText;
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
