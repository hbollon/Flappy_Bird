#ifndef PIPEDOWN_H
#define PIPEDOWN_H

#include <iostream>
#include <SFML/Graphics.hpp>

class PipeDown
{
public:
    PipeDown();
    sf::Sprite getSpritePipeDown();
    void generatePipes();

private:
    sf::Sprite s_pipeDown;
    sf::Texture t_pipeDown;
    int pipeDX;
    int pipeDY;
};

#endif // PIPEDOWN_H
