#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <Windows.h>
#include "Game.h"

#define BACKGROUND_COLOR {20,88,60}

int main()
{
    ShowWindow(GetConsoleWindow(),SW_HIDE);
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) { std::cout << "Error font add"; }
    sf::RenderWindow Saper(sf::VideoMode(0,0), "Saper",sf::Style::Fullscreen);
    Game* Game_Saper = new Game(Saper ,font);
    sf::Event event;
    
    bool menu = 0;
    bool game = 0;
     
    while (Saper.isOpen())
    {
        Saper.clear(BACKGROUND_COLOR);
       
        while (Saper.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                if (Game_Saper != nullptr)
                {
                    delete Game_Saper;
                }
                Saper.close();
            }     
        }
        if (!(menu))
        {
            menu = Game_Saper->Menu_make(event, Saper);
            game = menu;
            Saper.pollEvent(event);
        }
        if (game)
        {
            game = Game_Saper->Game_make(event, Saper);
            menu = game;     
        }
        Saper.display();
    }
    delete Game_Saper;
    return 0;
}

