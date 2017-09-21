#include <iostream>
#include "player.h"

sf::Vector2f velocity = (sf::Vector2f(4.f,0.f));

player::player()
{
    if (!t_bird1.loadFromFile("frame-1.png"))
    {
        std::cout << "Error when loading frame-1.png" << std::endl;
    }
    else
    {
        std::cout << "Loading frame-1.png successful" << std::endl;
    }

    if (!t_bird2.loadFromFile("frame-2.png"))
    {
        std::cout << "Error when loading frame-2.png" << std::endl;
    }
    else
    {
        std::cout << "Loading frame-2.png successful" << std::endl;
    }

    if (!t_bird3.loadFromFile("frame-3.png"))
    {
        std::cout << "Error when loading frame-3.png" << std::endl;
    }
    else
    {
        std::cout << "Loading frame-3.png successful" << std::endl;
    }

    if (!t_bird4.loadFromFile("frame-4.png"))
    {
        std::cout << "Error when loading frame-4.png" << std::endl;
    }
    else
    {
        std::cout << "Loading frame-4.png successful" << std::endl;
    }

    m_counterAnim = 1;

    s_bird.setTexture(t_bird1);
    s_bird.setPosition(0, 490);
}

sf::Sprite player::getSprite()
{
    return s_bird;
}

void player::getPosition()
{
    m_X = s_bird.getPosition().x;
    m_Y = s_bird.getPosition().y;
}

int player::getX() const
{
    return m_X;
}

int player::getY() const
{
    return m_Y;
}

void player::animation()
{
    switch (m_counterAnim)
    {
    case 0:
        s_bird.setTexture(t_bird1);
        break;

    case 1:
        s_bird.setTexture(t_bird2);
        break;

    case 2:
        s_bird.setTexture(t_bird3);
        break;

    case 3:
        s_bird.setTexture(t_bird4);
        break;
    }

    m_counterAnim++;

    if (m_counterAnim >= 4)
        m_counterAnim = 0;

}

void player::gravity()
{
    s_bird.move(velocity.x, velocity.y);

    if(s_bird.getPosition().y < ground && s_bird.getPosition().y >= 0)
    {
        velocity.y += m_gravity;
    }
    else if (s_bird.getPosition().y >= ground)
    {
        s_bird.setPosition(s_bird.getPosition().x, ground);
        velocity.y = 0;
    }
    else if (s_bird.getPosition().y <= 0)
    {
        s_bird.setPosition(s_bird.getPosition().x, 0);
        velocity.y = 0;
    }
}

void player::jump()
{
    velocity.y += -10;
}
