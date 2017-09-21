#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>


class player
{
public:
    player();
    sf::Sprite getSprite();
    void animation();
    void jump();
    void gravity();
    void getPosition();
    int getX() const;
    int getY() const;

private:
    int m_counterAnim;
    sf::Sprite s_bird;
    sf::Texture t_bird1;
    sf::Texture t_bird2;
    sf::Texture t_bird3;
    sf::Texture t_bird4;
    float m_X;
    float m_Y;
    int ground = 865;
    const float m_gravity = 0.4;
};

#endif // PLAYER_H
