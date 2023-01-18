#include "renderer.h"

#include "scene.h"
#include "entities/ball.h"
#include "entities/hole.h"

#include "misc/math.h"
#include <iostream>
#include <format>

#include <SFML/System.hpp>

void Renderer::render(sf::RenderWindow& window, Scene& scene)
{
    /* clear previous frame */
    window.clear(sf::Color(12, 12, 12));

    /* draw here*/
    scene.get_score_counter()->get_text().setPosition(window.getView().getCenter());
    window.draw(scene.get_score_counter()->get_text());

    window.draw(scene.get_hole()->get_shape());
    window.draw(scene.get_ball()->get_shape());

    /* call opengl stuff to display the frame */
    window.display();
}