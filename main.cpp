#include <iostream>
#include <time.h>
#include "player.h"
#include "game.h"
#include "ground.h"
#include "pipedown.h"
#include "pipeup.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int i=0;

int main()
{
    sf::RenderWindow game(sf::VideoMode(1920, 1080), "Flappy Bird", sf::Style::Fullscreen);

    game.setFramerateLimit(60);
    game.setKeyRepeatEnabled(false);

    player bird;
    PipeUp pipeU;
    PipeDown pipeD;
    ground ground1(-500);
    ground ground2(1420);

    loadTextures();

    sf::Vector2f center(bird.getX() + 700, bird.getY() + 530);
    sf::Vector2f size (1920,1080);
    sf::View vue (center, size);

    while (game.isOpen())
    {
        if (i>6)
        {
        bird.animation();
        i=0;
        }
        i++;

        sf::Event event;

        while (game.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game.close();

            if (event.type == sf::Event::KeyPressed)
                if(event.key.code == sf::Keyboard::Escape)
                    game.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    bird.jump();
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

        if (counterT >= 100)
        {
            counterT = 0;
            random = 0;
            srand(time(NULL));
            random = (rand() % (MAX - MIN + 1)) + MIN;
        }

        counter++;
        counterT++;

        game.clear();

        game.draw(s_background);
        game.draw(ground1.getSpriteGround());
        game.draw(ground2.getSpriteGround());
        game.draw(pipeU.getSpritePipeUp());
        game.draw(pipeD.getSpritePipeDown());
        game.draw(bird.getSprite());

        vue.setCenter(center);
        game.setView(vue);
        bird.getPosition();

        center.x = bird.getX() + 700;

        game.display();
    }

    return 0;
}

void loadTextures()
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
    s_background.setPosition(back_X, back_Y);
}