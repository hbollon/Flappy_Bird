#include "pipedown.h"

PipeDown::PipeDown(int X, int Y)
{
    if (!t_pipeDown.loadFromFile("pipe_down.png"))
    {
        std::cout << "Error when loading pipe_down.png" << std::endl;
    }
    else
    {
        std::cout << "Loading pipe_down.png successful" << std::endl;
    }

    pipeDX = X;
    pipeDY = Y;
    s_pipeDown.setTexture(t_pipeDown);
    s_pipeDown.setPosition(X, Y);
}

float PipeDown::getX() const
{
    return s_pipeDown.getPosition().x;
}

sf::Sprite PipeDown::getSpritePipeDown() const
{
    return s_pipeDown;
}

sf::IntRect PipeDown::getBoundingBox() const
{
    sf::IntRect boundingBox(s_pipeDown.getGlobalBounds());
    return boundingBox;
}

void PipeDown::generatePipes(int Y)
{
    pipeDY = Y;
    pipeDX += 2400;
    s_pipeDown.setPosition(pipeDX, pipeDY);
}
