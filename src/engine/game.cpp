#include "game.h"

#include "scene.h"
#include "misc/math.h"

Game::Game(Configuration config) :
    m_scene(Scene(config.width, config.height))
{
    m_window.create(
        sf::VideoMode(config.width, config.height),
        config.name,
        sf::Style::Titlebar | sf::Style::Close
    );

    m_window.setVerticalSyncEnabled(true);
}

Game::~Game()
{

}

void Game::run()
{
    while (m_window.isOpen())
    {
        handle_events();

        m_scene.get_ball()->handle_movement();
        m_scene.get_ball()->handle_collision(m_scene);

        m_renderer.render(m_window, m_scene);
    }
}

bool Game::is_window_active() const
{
    return m_is_window_active;
}

void Game::handle_events()
{
    /* scoring a point */
    if (m_scene.get_ball()->collides_with(m_scene.get_hole()))
    {
        m_scene.get_hole()->reset();
        m_scene.get_hole()->set_position(m_scene.get_random_point());

        m_scene.get_ball()->set_radius(m_scene.get_ball()->get_radius() + 1.f);
        m_scene.get_score_counter()->increase();
        m_scene.get_score_counter()->get_text().setPosition(m_window.getView().getCenter());
    }

    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                m_window.close();
                break;
            }
            case sf::Event::GainedFocus:
            {
                m_is_window_active = true;
                break;
            }
            case sf::Event::LostFocus:
            {
                m_is_window_active = false;
                break;
            }
            case sf::Event::KeyReleased:
            {
                if (event.key.code == sf::Keyboard::R)
                {
                     /* game restart */
                     m_scene.reset_scene();
                }
            }
        }
    }
}