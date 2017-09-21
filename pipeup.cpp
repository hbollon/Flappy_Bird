#include "pipeup.h"

PipeUp::PipeUp()
{
    if (!t_pipeUp.loadFromFile("pipe_up.png"))
    {
        std::cout << "Error when loading pipe_up.png" << std::endl;
    }
    else
    {
        std::cout << "Loading pipe_up.png successful" << std::endl;
    }

    s_pipeUp.setTexture(t_pipeUp);
    s_pipeUp.setPosition(1920, 600);
}

sf::Sprite PipeUp::getSpritePipeUp()
{
    return s_pipeUp;
}
