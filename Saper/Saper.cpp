#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <Windows.h>

#include "Game.h"

int main()
{
    //tworzenie okna
    sf::RenderWindow Saper(sf::VideoMode(0,0), "Saper",sf::Style::Fullscreen);
    Game* Game_Saper = new Game(Saper);
    sf::Event event;
 
    bool menu = 0;
    bool game = 0;
      
    while (Saper.isOpen())
    {
        Saper.clear(sf::Color (20,88,60));
       
        while (Saper.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                Saper.close();
            }     
        }
        if (!(menu))
        {
            menu = Game_Saper->menu(event, Saper);
            game = menu;
        }
        if (game)
        {
            game = Game_Saper->game(event, Saper);
            menu = game;
        }
        
        Saper.display();
    }

    delete Game_Saper;
    return 0;
}