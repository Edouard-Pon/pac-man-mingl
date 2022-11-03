#include "Game.h"
#include <thread>

using namespace std;


Game *game = nullptr;

int main(int argc, char* args[])
{
    const int FPS_LIMIT = 60;
    chrono::milliseconds frameDelay = chrono::milliseconds(1000 / FPS_LIMIT);

    chrono::time_point<chrono::steady_clock> frameStart;
    chrono::microseconds frameTime = chrono::microseconds::zero();

    game = new Game();
    game->init("Pac-Man", 128, 128, 640, 480);

    while (game->running()) {
        frameStart = chrono::steady_clock::now();

        game->handleEvents();
        game->update();
        game->render();

        this_thread::sleep_for(frameDelay - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - frameStart));
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - frameStart);
    }

    game->clean();

    return 0;
}
