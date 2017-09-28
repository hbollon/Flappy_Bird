#include <iostream>
#include <ctime>
#include <random>
#include "player.h"
#include "game.h"
#include "ground.h"
#include "pipedown.h"
#include "pipeup.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    //Initialisation boucle de jeu
    sf::RenderWindow game(sf::VideoMode(1920, 1080), "Flappy Bird", sf::Style::Fullscreen);

    game.setFramerateLimit(60);
    game.setKeyRepeatEnabled(false);

    int i=0;
    int o=0;
    int counter = 0;
    int counterT = 0;
    int random = 0;
    int begin = 0;
    int gameStatut = 1;
    int pipeCounter = 0;
    float back_X = -300.f;
    float back_Y = -30.f;
    int testGround = 0;

    std::random_device rd;
    std::mt19937 generator(rd());
    generator.seed((unsigned int)time(NULL));
    std::uniform_int_distribution<int> distribution(300,800);

    player bird;

    random = distribution(generator);
    PipeUp pipeU(1920, random);
    PipeDown pipeD(1920, -1300 + random);
    random = distribution(generator);
    PipeUp pipeU2(2520, random);
    PipeDown pipeD2(2520, -1300 + random);
    random = distribution(generator);
    PipeUp pipeU3(3120, random);
    PipeDown pipeD3(3120, -1300 + random);
    random = distribution(generator);
    PipeUp pipeU4(3720, random);
    PipeDown pipeD4(3720, -1300 + random);

    ground ground1(-500);
    ground ground2(1420);

    sf::Vector2f center(bird.getX() + 700, bird.getY() + 45);
    sf::Vector2f size (1920,1080);
    sf::View vue (center, size);

    sf::Event event;

    loadTextures(back_X, back_Y);

    //Boucle de jeu
    while (game.isOpen())
    {
        while(bird.getSprite().getGlobalBounds().intersects(pipeU.getSpritePipeUp().getGlobalBounds()) != 1 && bird.getSprite().getGlobalBounds().intersects(pipeU2.getSpritePipeUp().getGlobalBounds()) != 1 && bird.getSprite().getGlobalBounds().intersects(pipeU3.getSpritePipeUp().getGlobalBounds()) != 1 && bird.getSprite().getGlobalBounds().intersects(pipeU4.getSpritePipeUp().getGlobalBounds()) != 1 && bird.getSprite().getGlobalBounds().intersects(pipeD.getSpritePipeDown().getGlobalBounds()) != 1 && bird.getSprite().getGlobalBounds().intersects(pipeD2.getSpritePipeDown().getGlobalBounds()) != 1 && bird.getSprite().getGlobalBounds().intersects(pipeD3.getSpritePipeDown().getGlobalBounds()) != 1 && bird.getSprite().getGlobalBounds().intersects(pipeD4.getSpritePipeDown().getGlobalBounds()) != 1)
        {
            if (i>6)
            {
            bird.animation();
            i=0;
            }
            i++;

            while (game.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    game.close();

                if (event.type == sf::Event::KeyPressed)
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape :
                            game.close();
                        break;

                        case sf::Keyboard::Space :
                            bird.jump();
                        break;

                        default :
                        break;
                    }
                }
            }

            bird.gravity();
            s_background.setPosition(back_X += 4, back_Y);

            if (counter >= 480)
            {
                counter = 0;
                switch (testGround)
                {
                case 0:
                    ground1.moveGround();
                    testGround++;
                    break;
                case 1:
                    ground2.moveGround();
                    testGround = 0;
                    break;
                default:
                    break;
                }
             }

            if (counterT >= 154)
            {
                counterT = 0;

                if(begin <= 2)
                    begin++;
                else
                {
                    pipeCounter++;
                    random = distribution(generator);
                    int diff = -1300 + random;

                    switch(pipeCounter)
                    {
                    case 1:
                        pipeU.generatePipes(random);
                        pipeD.generatePipes(diff);
                        break;
                    case 2:
                        pipeU2.generatePipes(random);
                        pipeD2.generatePipes(diff);
                        break;
                    case 3:
                        pipeU3.generatePipes(random);
                        pipeD3.generatePipes(diff);
                        break;
                    case 4:
                        pipeU4.generatePipes(random);
                        pipeD4.generatePipes(diff);
                        pipeCounter = 0;
                        break;
                    default:
                        break;
                    }
                }
            }


            counter++;
            counterT++;

            game.clear();

            game.draw(s_background);
            game.draw(ground1.getSpriteGround());
            game.draw(ground2.getSpriteGround());
            game.draw(pipeU.getSpritePipeUp());
            game.draw(pipeU2.getSpritePipeUp());
            game.draw(pipeU3.getSpritePipeUp());
            game.draw(pipeU4.getSpritePipeUp());
            game.draw(pipeD.getSpritePipeDown());
            game.draw(pipeD2.getSpritePipeDown());
            game.draw(pipeD3.getSpritePipeDown());
            game.draw(pipeD4.getSpritePipeDown());
            game.draw(bird.getSprite());

            vue.setCenter(center);
            game.setView(vue);

            center.x = bird.getX() + 700;

            game.display();
        }
    }

    return 0;
}

void loadTextures(float X, float Y)
{
    if (!t_background.loadFromFile("background.png"))
    {
        std::cout << "Error when loading background.png" << std::endl;
    }
    else
    {
        std::cout << "Loading background.png successful" << std::endl;
    }

    s_background.setTexture(t_background);
    s_background.setPosition(X, Y);
}
