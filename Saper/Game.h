#include "Box.h"
#include "Map.h"
#include "Texts.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include <Windows.h>

class Game
{
public:
	sf::Font font;
    Texts* lv_ea;
    Texts* lv_me;
    Texts* lv_ha;
    Texts* reset;
    Texts* win ;
    Texts* lost;
    unsigned int window_w, window_h ;
    unsigned int* Game_m_w = new unsigned int, * Game_m_h = new unsigned int, * Mines_on_map = new unsigned int;
    Map* game_map;

public:
	Game(sf::RenderWindow& Saper);
	~Game();
    bool menu(sf::Event &event,sf::RenderWindow &Saper);
    bool game(sf::Event &event, sf::RenderWindow& Saper);
};

