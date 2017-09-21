#include "pipedown.h"

PipeDown::PipeDown()
{
    if (!t_pipeDown.loadFromFile("pipe_down.png"))
    {
        std::cout << "Error when loading pipe_down.png" << std::endl;
    }
    else
    {
        std::cout << "Loading pipe_down.png successful" << std::endl;
    }

    s_pipeDown.setTexture(t_pipeDown);
    s_pipeDown.setPosition(1920, 0);
}

sf::Sprite PipeDown::getSpritePipeDown()
{
    return s_pipeDown;
}
