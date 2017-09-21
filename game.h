#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

sf::Sprite s_background;
sf::Texture t_background;
int testGround = 0;
int counter = 0;
int counterT = 0;
int MAX = 0;
int MIN = 0;
int random = 0;
float back_X = -300.f;
float back_Y = -30.f;
void loadTextures();


#endif // GAME_H
