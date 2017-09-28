#include "pipeup.h"

PipeUp::PipeUp(int X, int Y)
{
    if (!t_pipeUp.loadFromFile("pipe_up.png"))
    {
        std::cout << "Error when loading pipe_up.png" << std::endl;
    }
    else
    {
        std::cout << "Loading pipe_up.png successful" << std::endl;
    }

    pipeUX = X;
    pipeUY = Y;
    s_pipeUp.setTexture(t_pipeUp);
    s_pipeUp.setPosition(X, Y);
}

sf::Sprite PipeUp::getSpritePipeUp() const
{
    return s_pipeUp;
}

sf::IntRect PipeUp::getBoundingBox() const
{
    sf::IntRect boundingBox(s_pipeUp.getGlobalBounds());
    return boundingBox;
}

void PipeUp::generatePipes(int Y)
{
    pipeUY = Y;
    pipeUX += 2400;
    s_pipeUp.setPosition(pipeUX, pipeUY);
}
