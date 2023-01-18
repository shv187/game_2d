#pragma once

#include <memory>

#include "misc/random.h"

#include "entities/ball.h"
#include "entities/hole.h"
#include "entities/score_counter.h"

class Scene
{
public:
    Scene(uint32_t width, uint32_t height);

public:
    uint32_t get_width() const;
    uint32_t get_height() const;

public:
    Ball* get_ball();
    Hole* get_hole();
    ScoreCounter* get_score_counter();

    void reset_scene();

public:
    sf::Vector2f get_random_point() const;

private:
    uint32_t m_width{};
    uint32_t m_height{};

    std::unique_ptr<ScoreCounter> m_score_counter{};
    std::unique_ptr<Ball> m_ball{};
    std::unique_ptr<Hole> m_hole{};
};