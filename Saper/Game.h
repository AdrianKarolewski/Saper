#include "Box.h"
#include "Map.h"
#include "Texts.h"

#include <time.h>
#define TIME_FOR_GAME 1000

#define CHAR_SIZE_1 0.045
#define TIME_FOR_BOMB 20

#define GAME_M_W_1 10
#define GAME_M_H_1 16
#define MINES_ON_M_1 30

#define GAME_M_W_2 20
#define GAME_M_H_2 30
#define MINES_ON_M_2 90

#define GAME_M_W_3 40
#define GAME_M_H_3 30
#define MINES_ON_M_3 200

class Game
{
public:
    Game(sf::RenderWindow& Saper,sf::Font & font);
    ~Game();
    void Center_txt(Map* m1, const unsigned int& secounds);
    bool Menu_make(sf::Event& event, sf::RenderWindow& Saper);
    bool Game_make(sf::Event& event, sf::RenderWindow& Saper);
private:
    
    Texts* lv_ea{ nullptr }, * lv_me{ nullptr }, * lv_ha{ nullptr }, * reset{ nullptr }, 
        * end_in_menu{ nullptr }, * end_in_game{ nullptr }, * back_to_menu{ nullptr }, *clock{ nullptr };
    Texts* lifebuoy{ nullptr }, *n_o_flags{ nullptr };
    sf::RectangleShape *win{ nullptr }, *lost{ nullptr };
    unsigned int secounds{ 0 };
    unsigned int taken_time{ 0 };
    bool show_one_bomb{ 1 };
    unsigned int Game_m_w{ 0 }, Game_m_h{ 0 }, Mines_on_map{ 0 };
    Map* game_map{ nullptr };
    clock_t start = 0;
};

