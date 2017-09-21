#ifndef PIPEUP_H
#define PIPEUP_H

#include <iostream>
#include <SFML/Graphics.hpp>

class PipeUp
{
public:
    PipeUp();
    sf::Sprite getSpritePipeUp();
    void generatePipes();

private:
    sf::Sprite s_pipeUp;
    sf::Texture t_pipeUp;
    int pipeUX;
    int pipeUY;
};

#endif // PIPEUP_H
