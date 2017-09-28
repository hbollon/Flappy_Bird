#include "ground.h"

ground::ground(float X)
{
    if (!t_ground.loadFromFile("ground.png"))
    {
        std::cout << "Error when loading ground.png" << std::endl;
    }
    else
    {
        std::cout << "Loading ground.png successful" << std::endl;
    }

    groundX = X;

    s_ground.setTexture(t_ground);
    s_ground.setPosition(groundX, groundY);

}

sf::Sprite ground::getSpriteGround() const
{
    return s_ground;
}

void ground::moveGround()
{
    groundX += 3840;
    s_ground.setPosition(groundX, groundY);
}
