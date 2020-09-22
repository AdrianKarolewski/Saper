#include "Game.h"
#include "Map.h"
#include "Box.h"
#include "Texts.h"
#include <iostream>

Game::Game(sf::RenderWindow &Saper)
{
    if (!font.loadFromFile("Arial.ttf")) { std::cout << "Error font add";}
    window_w = Saper.getSize().x;
    window_h = Saper.getSize().y;
    
    lv_ea = new Texts(font, "Lv_easy",   { 0, 0, 255 }, 0.045 * window_h,  { static_cast < float>(0.156 * window_w),static_cast <float>(0.092 * window_h) }, { static_cast<float>(window_w / 2),static_cast <float>(0.324 * window_h) });
    lv_me = new Texts(font, "Lv_medium", { 0, 0, 255 }, 0.045 * window_h,  { static_cast <float>(0.156 * window_w),static_cast <float>(0.092 * window_h) }, { static_cast<float>(window_w / 2),static_cast <float>(0.462 * window_h) });
    lv_ha = new Texts(font, "Lv_hard",   { 0, 0, 255 }, 0.045 * window_h,  { static_cast <float>(0.156 * window_w),static_cast <float>(0.092 * window_h) }, { static_cast<float>(window_w / 2),static_cast <float>(0.601 * window_h) });
    end_in_menu = new Texts(font, "Exit",{ 0, 0, 255 }, 0.045 * window_h,  { static_cast <float>(0.156 * window_w),static_cast <float>(0.092 * window_h) }, { static_cast<float>(window_w / 2),static_cast <float>(0.740 * window_h) });

    reset = new Texts(font, "Reset",       { 0,0,255 }, 0.045 * window_h, { static_cast <float>(0.104 * window_w),static_cast <float>(0.074 * window_h) }, { static_cast<float>(window_w) - static_cast<float>(0.119 * window_w), static_cast <float>(0.120 * window_h) });
    back_to_menu = new Texts(font, "Menu", { 0,0,255 }, 0.045 * window_h, { static_cast <float>(0.104 * window_w),static_cast <float>(0.074 * window_h) }, { static_cast<float>(window_w) - static_cast<float>(0.119 * window_w), static_cast <float>(0.212 * window_h) });
    end_in_game = new Texts(font, "Exit",  { 0,0,255 }, 0.045 * window_h, { static_cast <float>(0.104 * window_w),static_cast <float>(0.074 * window_h) }, { static_cast<float>(window_w) - static_cast<float>(0.119 * window_w), static_cast <float>(0.305 * window_h) });
    
    win = new Texts(font, "WIN",     { 255,255,255 }, 0.055 * window_h,  { static_cast <float>(0.130 * window_w),static_cast <float>(0.138 * window_h) }, { static_cast<float>(window_w) / 2,static_cast<float>(window_h)/2 });
    lost = new Texts(font, "BOOOM",  { 0,0,0 },       0.092 * window_h,  { static_cast <float>(0.442 * window_w),static_cast <float>(0.694 * window_h) }, { static_cast<float>(window_w) / 2, static_cast<float>(window_h)/2 });
    
    win->box_for_text.setFillColor({ 200,50,50 });
    lost->box_for_text.setOutlineThickness(NULL);

    clock = new Texts(font, "",     { 0,0,255 }, 0.037 * window_h,{ static_cast <float>(0.156 * window_w),static_cast <float>(0.074 * window_h) }, { static_cast <float>(0.104 * window_w),static_cast <float>(0.120 * window_h) });
    n_o_flags = new Texts(font, "", { 0,0,255 }, 0.037 * window_h, { static_cast <float>(0.156 * window_w),static_cast <float>(0.074 * window_h) }, { static_cast <float>(0.104 * window_w),static_cast <float>(0.212 * window_h) });

    lifebuoy = new Texts(font, "Bobm for time",  { 0,0,255 }, 0.037 * window_h, { static_cast <float>(0.156 * window_w),static_cast <float>(0.074 * window_h) }, { static_cast <float>(0.104 * window_w),static_cast <float>(0.305 * window_h) });
}
Game::~Game()
{
    delete lv_ea, lv_me, lv_ha, reset, win, lost,end_in_game,end_in_menu,back_to_menu,clock,lifebuoy,n_o_flags;
    delete Game_m_h, Game_m_w, Mines_on_map;

    if (game_map != nullptr) { delete game_map; }
}

void Game::center_txt(Map* m1,const unsigned int &s)
{
    if (999 - s > 998)
    {
        clock->text_on_map.setOrigin(clock->text_on_map.getGlobalBounds().width / 2, clock->text_on_map.getGlobalBounds().height / 2 + clock->text_on_map.getCharacterSize() / 4);
        clock->text_on_map.setPosition(clock->box_for_text.getPosition());
    }
    else if ((999 - s < 100) && (999 - s > 98))
    {
        clock->text_on_map.setOrigin(clock->text_on_map.getGlobalBounds().width / 2, clock->text_on_map.getGlobalBounds().height / 2 + clock->text_on_map.getCharacterSize() / 4);
        clock->text_on_map.setPosition(clock->box_for_text.getPosition());
    }  
    if (game_map->how_much_put_flags == 0)
    {
        n_o_flags->text_on_map.setOrigin(n_o_flags->text_on_map.getGlobalBounds().width / 2, n_o_flags->text_on_map.getGlobalBounds().height / 2 + n_o_flags->text_on_map.getCharacterSize() / 4);
        n_o_flags->text_on_map.setPosition(n_o_flags->box_for_text.getPosition());
    }
    else if ((game_map->how_much_put_flags > 8) && (game_map->how_much_put_flags < 11))
    {
        n_o_flags->text_on_map.setOrigin(n_o_flags->text_on_map.getGlobalBounds().width / 2, n_o_flags->text_on_map.getGlobalBounds().height / 2 + n_o_flags->text_on_map.getCharacterSize() / 4);
        n_o_flags->text_on_map.setPosition(n_o_flags->box_for_text.getPosition());
    }
}

bool Game::menu(sf::Event &event,sf::RenderWindow &Saper)
{
    bool choose_lv = 0;

    Saper.draw(*lv_ea);
    Saper.draw(*lv_me);
    Saper.draw(*lv_ha);
    Saper.draw(*end_in_menu);

    unsigned int mouse_x;
    unsigned int mouse_y;

    if (event.mouseButton.button == sf::Mouse::Left)
    {
        mouse_x = event.mouseButton.x;
        mouse_y = event.mouseButton.y;
        if (lv_ea->click_on_text_box(mouse_x,mouse_y))
        {
            choose_lv = 1;
            *Game_m_w = 10;
            *Game_m_h = 16;
            *Mines_on_map = 30;
        }
        else if (lv_me->click_on_text_box(mouse_x, mouse_y))
        {
            choose_lv = 1;
            *Game_m_w = 20;
            *Game_m_h = 30;
            *Mines_on_map = 100;
            
        }
        else if (lv_ha->click_on_text_box(mouse_x, mouse_y))
        {
            choose_lv = 1;
            *Game_m_w = 40;
            *Game_m_h = 30;
            *Mines_on_map = 220;
            
        }
        else if (end_in_menu->click_on_text_box(mouse_x, mouse_y))
        {
            Saper.close();
        }
        if (choose_lv)
        {
            game_map = new Map(*Game_m_w, *Game_m_h, *Mines_on_map, Saper);
            game_map = game_map->append_mines_add_val(game_map);
            
            start = std::clock();
        }
    }
    return choose_lv;
}
bool Game::game(sf::Event& event, sf::RenderWindow& Saper)
{ 
    bool choose_lv = 1;
    
    unsigned int mouse_x;
    unsigned int mouse_y;

    secounds += taken_time;
    clock->text_on_map.setString("Time: " + std::to_string(999 - secounds));
    n_o_flags->text_on_map.setString(std::to_string(game_map->how_much_put_flags) + "/" + std::to_string(game_map->c_mines));

    center_txt(game_map, secounds);
    // lost
    if (1000 - secounds == 1)
    {
        game_map->show_boombs();
        game_map->lost_b = 1;
    }
    else
    {
        secounds = (std::clock() - start) / CLOCKS_PER_SEC;
    }

    Saper.draw(*reset);
    Saper.draw(*end_in_game);
    Saper.draw(*back_to_menu);
    Saper.draw(*clock);
    Saper.draw(*n_o_flags);
    Saper.draw(*lifebuoy);

    mouse_x = event.mouseButton.x;
    mouse_y = event.mouseButton.y;
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        if (reset->click_on_text_box(mouse_x, mouse_y))
        {
            delete game_map;
            game_map = new Map(*Game_m_w, *Game_m_h, *Mines_on_map, Saper);
            taken_time = 0;
            start = 0;
            game_map = game_map->append_mines_add_val(game_map);
        }
        if (end_in_game->click_on_text_box(mouse_x, mouse_y))
        {
            Saper.close();
        }
        if (back_to_menu->click_on_text_box(mouse_x, mouse_y))
        {
            delete game_map;
            return 0;
        }
        if (lifebuoy->click_on_text_box(mouse_x, mouse_y))
        {
            mouse_x = 0;
            mouse_y = 0;
            event.mouseButton.x = 0;
            event.mouseButton.y = 0;
            if (secounds + taken_time + 50 < 900)
            {
                
                taken_time += 50;
                game_map->show_one_bomb();
            }             
        }
    }   
    game_map->draw_boxes(Saper, game_map);
    
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (game_map->click_on_map(mouse_x, mouse_y))
        {
            game_map->click_handle(mouse_x, mouse_y,Saper,event);
        }     
    }
    if (game_map->win_b)
    {
        Saper.draw(*win);
    }
    else if (game_map->lost_b)
    {
        lost->box_for_text.setTexture(&game_map->texturs[12]);
        Saper.draw(*lost);
    }
    return choose_lv;
}