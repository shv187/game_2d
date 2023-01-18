#pragma once

#include <SFML/Graphics.hpp>

class ScoreCounter
{
public:
    ScoreCounter();

public:
    sf::Text& get_text();

public:
    void increase();
    void reset();

private:
    void update_text();

private:
    sf::RenderWindow m_window{};
    bool m_initialized{};
    sf::Text m_text{};
    sf::Font m_font{};
    int m_score{};
};