#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include <Windows.h>

#include "Box.h"
#include "Map.h"
#include "Texts.h"


int window_w = GetSystemMetrics(SM_CXSCREEN), window_h = GetSystemMetrics(SM_CYSCREEN);

bool menu(sf::Event event,unsigned int * g_m_w, unsigned int* g_m_h, unsigned int* m_o_m)
{
    bool choose_lv = 0;
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        if ((event.mouseButton.x > window_w/2 - 150.f) && (event.mouseButton.x < window_w/2 + 150.f))
        {
            if ((event.mouseButton.y > 300) && (event.mouseButton.y < 400))
            {
                choose_lv = 1;
                *g_m_w = 10;
                *g_m_h = 16;
                *m_o_m = 30;
            }
            else if ((event.mouseButton.y > 450) && (event.mouseButton.y < 550))
            {
                choose_lv = 1;
                *g_m_w = 20;
                *g_m_h = 30;
                *m_o_m = 90;
            }
            else if ((event.mouseButton.y > 600) && (event.mouseButton.y < 700))
            {
                choose_lv = 1;
                *g_m_w = 40;
                *g_m_h = 30;
                *m_o_m = 200;
            }
        }
    }
    return choose_lv;
}
bool game(sf::Event event,Map * g_map_f, sf::RenderWindow *Saper_game)
{
    long long *click_x = new long long, *click_y = new long long;
    bool choose_lv = 1;

    g_map_f->draw_boxes(*Saper_game, g_map_f);
    if (event.type == sf::Event::MouseButtonPressed)
    {
        *click_x = ((event.mouseButton.x  + static_cast<long long>(30 * g_map_f->map_w /2) - (window_w / 2))) / 30;
        *click_y = ((event.mouseButton.y  + static_cast<long long>(30 * g_map_f->map_h /2) - (window_h / 2)))/ 30;
        
        if ((event.mouseButton.x > 1235) && (event.mouseButton.x < 1385) && (event.mouseButton.y > 35) && (event.mouseButton.y < 75))
        {
            choose_lv = 0;
        }
        if (!((*click_x > (g_map_f->map_w - 1)) || (*click_y > (g_map_f->map_h - 1))) && (!(*click_x < 0  || *click_y < 0)))
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                if (!g_map_f->t_boxes[*click_y][*click_x].is_block_b())
                {
                    g_map_f = g_map_f->flagged_box(*click_x, *click_y, g_map_f);
                }
            }
            if (event.mouseButton.button == sf::Mouse::Middle)
            {
                if (g_map_f->t_boxes[*click_y][*click_x].is_flagged_b())
                {
                    g_map_f = g_map_f->un_flagged_box(*click_x, *click_y, g_map_f);
                }
            }
            if (g_map_f->Is_win())
            {

            }
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if ((!g_map_f->t_boxes[*click_y][*click_x].is_block_b())
                    && (!g_map_f->t_boxes[*click_y][*click_x].is_flagged_b()))
                {
                    g_map_f->show_box(*click_x, *click_y);
                }
            }
        }
    }
    for (int i = 0; i < g_map_f->map_h; i++)
    {
        for (int j = 0; j < g_map_f->map_w; j++)
        {
            if (g_map_f->t_boxes[i][j].is_show_it() == 1)
            {
                g_map_f->show_box(j, i);
            }
        }
    }
    delete click_x, click_y;
    return choose_lv;
}
int main()
{
    //tworzenie okna
    sf::RenderWindow Saper(sf::VideoMode(window_w, window_h), "Saper");
    sf::Font font;
    sf::Event event;

    int resultgame = 0;
    
    
    Texts* lv_ea = new Texts(font, "Lv_easy", { 0, 0, 255 }, 50, { 600.f,315.f }, { 300.f,100.f }, { 700.f,350.f });
    Texts* lv_me = new Texts(font, "Lv_medium", {0, 0, 255}, 50, { 570.f,465.f }, { 300.f,100.f }, { 700.f,500.f });
    Texts* lv_ha = new Texts(font, "Lv_hard", { 0, 0, 255 }, 50, { 600.f,615.f }, { 300.f,100.f }, { 700.f,650.f });
    Texts *reset, *win, *lost;

    unsigned int * Game_m_w = new unsigned int, *Game_m_h = new unsigned int, *Mines_on_map = new unsigned int;
    bool is_lv_choose = 0;
    
    Map* g_map = nullptr;
    // schownanie konsoli
    

    if (!font.loadFromFile("Arial.ttf"))
    {
        std::cout << "Blad czcionki";
    }
    //petla gry
    while (Saper.isOpen())
    {
        Saper.clear(sf::Color (20,88,60));
        
        while (Saper.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Saper.close();
        }
        // czyszczenie ekranu i nadanie koloru
        
        //wyswietlanie menu
        if (!(is_lv_choose))
        {
            
            is_lv_choose = menu(event, Game_m_w, Game_m_h, Mines_on_map);
            // po wyborze tworzymy 
            if (is_lv_choose)
            {
               
                g_map = new Map(*Game_m_w, *Game_m_h, *Mines_on_map);
                g_map = g_map->append_mines_add_val(g_map);
                g_map->write_map();
                delete Game_m_h, Game_m_w, Mines_on_map;
                delete lv_ea, lv_me, lv_ha;
            }
        }
        //wyświetla rozgrywkę
        else if(is_lv_choose)
        {
            is_lv_choose = game(event, g_map, &Saper);
            if (!is_lv_choose)
            {
                delete g_map;
            }
        }
        Saper.display();
    }
    return 0;
}