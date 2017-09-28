#ifndef PIPEUP_H
#define PIPEUP_H

#include <iostream>
#include <SFML/Graphics.hpp>

class PipeUp
{
public:
    PipeUp(int X, int Y);
    sf::Sprite getSpritePipeUp() const;
    sf::IntRect getBoundingBox() const;
    void generatePipes(int Y);
    float getX() const;

private:
    sf::Sprite s_pipeUp;
    sf::Texture t_pipeUp;
    int pipeUX;
    int pipeUY;
};

#endif // PIPEUP_H
