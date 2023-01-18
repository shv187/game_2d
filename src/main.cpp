#include "engine/game.h"

#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Game::Configuration config{};
    config.name = "Game";
    config.width = 800;
    config.height = 800;

    Game(config).run();

    return 0;
}