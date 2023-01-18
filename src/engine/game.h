#pragma once

#include <string>
#include <cstdint>

#include <SFML/Graphics.hpp>

#include "renderer.h"
#include "scene.h"

class Game
{
public:
    struct Configuration
    {
        std::string name{ "Default Name" };
        uint32_t width{ 1280 };
        uint32_t height{ 720 };
    };

public:
    Game(Configuration config = Configuration());
    ~Game();

    void run();
    bool is_window_active() const;

private:
    void handle_events();

private:
    Configuration m_config{};
    sf::RenderWindow m_window{};
    Renderer m_renderer{};
    Scene m_scene;

    bool m_is_window_active{};
};