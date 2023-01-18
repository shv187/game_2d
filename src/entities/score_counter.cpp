#include "score_counter.h"

#include <format>

ScoreCounter::ScoreCounter()
{
    m_font.loadFromFile("resources\\fonts\\verdanab.ttf");

    update_text();
}

void ScoreCounter::increase()
{
    m_score++;
    update_text();
}

void ScoreCounter::reset()
{
    m_score = 0;
    update_text();
}

sf::Text& ScoreCounter::get_text()
{
    return m_text;
}

void ScoreCounter::update_text()
{
    m_text = sf::Text{ std::format("{}", m_score), m_font };
    m_text.setCharacterSize(72);
    m_text.setFillColor(sf::Color::White);

    auto text_global_bounds = sf::Vector2f{ m_text.getGlobalBounds().width, m_text.getGlobalBounds().height } / 2.f;
    auto text_local_bounds = text_global_bounds + sf::Vector2f{ m_text.getLocalBounds().left, m_text.getLocalBounds().top };
    m_text.setOrigin(text_local_bounds);
}