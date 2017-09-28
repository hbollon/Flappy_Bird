#ifndef PIPEDOWN_H
#define PIPEDOWN_H

#include <iostream>
#include <SFML/Graphics.hpp>

class PipeDown
{
public:
    PipeDown(int X, int Y);
    sf::Sprite getSpritePipeDown() const;
    sf::IntRect getBoundingBox() const;
    void generatePipes(int Y);
    float getX() const;

private:
    sf::Sprite s_pipeDown;
    sf::Texture t_pipeDown;
    int pipeDX;
    int pipeDY;
};

#endif // PIPEDOWN_H
