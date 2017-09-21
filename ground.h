#ifndef GROUND_H
#define GROUND_H

#include <iostream>
#include <SFML/Graphics.hpp>

class ground
{
public:
    ground(float X);
    void loadTexture();
    void moveGround();
    sf::Sprite getSpriteGround();

private:
    sf::Sprite s_ground;
    sf::Texture t_ground;
    int groundX;
    int groundY = 10;
};

#endif // GROUND_H
