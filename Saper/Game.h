#include "Box.h"
#include "Map.h"
#include "Texts.h"

class Game
{
public:
	sf::Font font;
    Texts* lv_ea , * lv_me, * lv_ha, * reset, * win, * lost, * end_in_menu, * end_in_game, * back_to_menu;
    unsigned int window_w, window_h ;
    unsigned int* Game_m_w = new unsigned int, * Game_m_h = new unsigned int, * Mines_on_map = new unsigned int;
    Map* game_map = nullptr;
    

public:
	Game(sf::RenderWindow& Saper);
	~Game();
    bool menu(sf::Event &event,sf::RenderWindow &Saper);
    bool game(sf::Event &event, sf::RenderWindow& Saper);
};

