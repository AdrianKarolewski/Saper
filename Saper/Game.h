#include "Box.h"
#include "Map.h"
#include "Texts.h"

#include <time.h>

class Game
{
	sf::Font font;
    Texts* lv_ea , * lv_me, * lv_ha, * reset, * win, * lost, * end_in_menu, * end_in_game, * back_to_menu,*clock;
    Texts* lifebuoy, *n_o_flags;
    unsigned int window_w, window_h ;
    unsigned int secounds = 0;
    unsigned int taken_time = 0;
    unsigned int* Game_m_w = new unsigned int, * Game_m_h = new unsigned int, * Mines_on_map = new unsigned int;
    Map* game_map = nullptr;
    clock_t start = 0;
public:
	Game(sf::RenderWindow& Saper);
	~Game();
 
    void center_txt(Map* m1, const unsigned int & secounds);

    bool menu(sf::Event& event, sf::RenderWindow& Saper);
    bool game(sf::Event& event, sf::RenderWindow& Saper);
};

