#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

class Scene;

class Entity
{
public:
    Entity(sf::Vector2f on_create_position);

public:
    const sf::CircleShape& get_shape() const;

public:
    const sf::Vector2f get_position() const;
    void set_position(const sf::Vector2f& new_position);

    const sf::Vector2f get_velocity() const;
    void set_velocity(const sf::Vector2f& new_velocity);

    float get_radius() const;
    void set_radius(float new_radius);

    void set_color(const sf::Color& color);

    void move(const sf::Vector2f distance);

    bool collides_with(Entity* other);

    void handle_collision(Scene& scene);
    void handle_movement();

protected:
    std::unique_ptr<sf::CircleShape> m_shape{};

    sf::Vector2f m_position{};
    sf::Vector2f m_velocity{};

    float m_radius{ 25.f };
};