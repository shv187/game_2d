#include "entity.h"

#include "engine/scene.h"
#include "misc/math.h"

Entity::Entity(sf::Vector2f on_create_position) :
    m_position(on_create_position)
{
    m_shape = std::make_unique<sf::CircleShape>(m_radius);
    m_shape->setPosition(m_position);
    m_shape->setOrigin({ m_radius, m_radius });
}

const sf::CircleShape& Entity::get_shape() const
{
    return *m_shape.get();
}

const sf::Vector2f Entity::get_position() const
{
    return m_position;
}

void Entity::set_position(const sf::Vector2f& new_position)
{
    m_position = new_position;
    m_shape->setPosition(m_position);
}

const sf::Vector2f Entity::get_velocity() const
{
    return m_velocity;
}

void Entity::set_velocity(const sf::Vector2f& new_velocity)
{
    m_velocity = new_velocity;
}

void Entity::move(const sf::Vector2f distance)
{
    m_position += distance;
    m_shape->setPosition(m_position);
}

void Entity::set_color(const sf::Color& color)
{
    m_shape->setFillColor(color);
}

float Entity::get_radius() const
{
    return m_shape->getRadius();
}

void Entity::set_radius(float new_radius)
{
    m_radius = new_radius;
    m_shape->setRadius(m_radius);
    m_shape->setOrigin({ m_radius, m_radius });
}

bool Entity::collides_with(Entity* other)
{
    return math::distance<float>(m_position, other->get_position()) <= m_radius + other->get_radius();
}

void Entity::handle_collision(Scene& scene)
{
        /* top collision */
    if (m_position.y < m_radius)
    {
        m_position = { m_position.x, m_radius };
        m_velocity.y = -m_velocity.y;
    }

    /* bottom collision */
    if (m_position.y > scene.get_height() - m_radius)
    {
        m_position = { m_position.x, (float)scene.get_height() - m_radius };
        m_velocity.y = -m_velocity.y;
    }

    /* left collision */
    if (m_position.x < m_radius)
    {
        m_position = { m_radius, m_position.y };
        m_velocity.x = -m_velocity.x;
    }

    /* right collision */
    if (m_position.x > scene.get_width() - m_radius)
    {
        m_position = { (float)scene.get_width() - m_radius, m_position.y };
        m_velocity.x = -m_velocity.x;
    }
}

void Entity::handle_movement()
{
    const float max_velocity{ 5.f };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_velocity.y > -max_velocity)
        m_velocity = { m_velocity.x, m_velocity.y - 0.5f };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_velocity.y < max_velocity)
        m_velocity = { m_velocity.x, m_velocity.y + 0.5f };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_velocity.x > -max_velocity)
        m_velocity = { m_velocity.x - 0.5f, m_velocity.y };

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_velocity.x < max_velocity)
        m_velocity = { m_velocity.x + 0.5f, m_velocity.y };

    move(m_velocity);
}