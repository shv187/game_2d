#include "engine/game.h"

int main()
{
    Game::Configuration config{};
    config.name = "Game";
    config.width = 800;
    config.height = 800;

    Game(config).run();

    return 0;
}