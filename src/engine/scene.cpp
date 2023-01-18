#include "scene.h"

Scene::Scene(uint32_t width, uint32_t height) :
    m_width(width),
    m_height(height)
{
    m_ball = std::make_unique<Ball>(sf::Vector2f(m_width / 2.f, m_height / 2.f));;
    m_hole = std::make_unique<Hole>(get_random_point());
    m_score_counter = std::make_unique<ScoreCounter>();
}

uint32_t Scene::get_width() const
{
    return m_width;
}

uint32_t Scene::get_height() const
{
    return m_height;
}

sf::Vector2f Scene::get_random_point() const
{
    return sf::Vector2f(
        Random::get<float>(0, m_width),
        Random::get<float>(0, m_height)
    );
}

Ball* Scene::get_ball()
{
    return m_ball.get();
}

Hole* Scene::get_hole()
{
    return m_hole.get();
}

ScoreCounter* Scene::get_score_counter()
{
    return m_score_counter.get();
}

void Scene::reset_scene()
{
    m_ball = std::make_unique<Ball>(sf::Vector2f(m_width / 2.f, m_height / 2.f));
    m_hole = std::make_unique<Hole>(get_random_point());
    m_score_counter = std::make_unique<ScoreCounter>();
}