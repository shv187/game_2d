#include "hole.h"

void Hole::reset()
{
    m_shape = std::make_unique<sf::CircleShape>(m_radius);
    m_shape->setPosition(m_position);
    m_shape->setOrigin({ m_radius, m_radius });
}