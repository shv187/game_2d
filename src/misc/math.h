#pragma once

#include <SFML/Graphics.hpp>

namespace math
{
    template<typename T>
    inline float length(sf::Vector2<T> v)
    {
        return sqrt(v.x * v.x + v.y * v.y);
    }

    template<typename T>
    inline float distance(sf::Vector2<T> start, sf::Vector2<T> destination)
    {
        return math::length(destination - start);
    }
}