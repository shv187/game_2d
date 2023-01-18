#pragma once

#include <SFML/Graphics.hpp>

class Scene;

class Renderer
{
public:
    void render(sf::RenderWindow& window, Scene& scene);
};