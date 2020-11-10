#include "Game.h"
#include "Map.h"
#include "Box.h"
#include "Texts.h"
#include <iostream>

Game::Game(sf::RenderWindow &Saper,sf::Font & font) :

lv_ea(new Texts(font, "Lv_easy", static_cast<int>(CHAR_SIZE_1 * Saper.getSize().y),
    { static_cast<float>(MEMU_BOX_W_S * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S * Saper.getSize().y) },
    { static_cast<float>(Saper.getSize().x / 2),static_cast <float>(0.324 * Saper.getSize().y)})),

lv_me(new Texts(font, "Lv_medium", static_cast<int>(CHAR_SIZE_1 * Saper.getSize().y),
    { static_cast <float>(MEMU_BOX_W_S * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S * Saper.getSize().y) },
    { static_cast<float>(Saper.getSize().x / 2),static_cast <float>(0.462 * Saper.getSize().y) })),

lv_ha(new Texts(font, "Lv_hard", static_cast<int>(CHAR_SIZE_1 * Saper.getSize().y),
    { static_cast <float>(MEMU_BOX_W_S * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S * Saper.getSize().y) },
    { static_cast<float>(Saper.getSize().x / 2),static_cast <float>(0.601 * Saper.getSize().y) })),

end_in_menu(new Texts(font, "Exit", static_cast<int>(CHAR_SIZE_1 * Saper.getSize().y),
    { static_cast <float>(MEMU_BOX_W_S * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S * Saper.getSize().y) },
    { static_cast<float>(Saper.getSize().x / 2),static_cast <float>(0.740 * Saper.getSize().y) })),

reset(new Texts(font, "Reset", static_cast<int>(CHAR_SIZE_1 * Saper.getSize().y),
    { static_cast <float>(MENU_BOX_W_S2 * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S2 * Saper.getSize().y) },
    { static_cast<float>(Saper.getSize().x * MENU_BOX_W_P),  static_cast <float>(0.120 * Saper.getSize().y) })),

back_to_menu(new Texts(font, "Menu", static_cast<int>(CHAR_SIZE_1 * Saper.getSize().y),
    { static_cast <float>(MENU_BOX_W_S2 * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S2 * Saper.getSize().y) },
    { static_cast<float>(Saper.getSize().x * MENU_BOX_W_P), static_cast <float>(0.212 * Saper.getSize().y) })),

end_in_game(new Texts(font, "Exit", static_cast<int>(CHAR_SIZE_1 * Saper.getSize().y),
    { static_cast <float>(MENU_BOX_W_S2 * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S2 * Saper.getSize().y) },
    { static_cast<float>(Saper.getSize().x * MENU_BOX_W_P), static_cast <float>(0.305 * Saper.getSize().y) })),

clock(new Texts(font, "", static_cast<int>(CHAR_SIZE_2* Saper.getSize().y),
    { static_cast <float>(MEMU_BOX_W_S * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S2 * Saper.getSize().y) },
    { static_cast <float>(MENU_BOX_W_P2 * Saper.getSize().x),static_cast <float>(0.120 * Saper.getSize().y) })),

n_o_flags(new Texts(font, "", static_cast<int>(CHAR_SIZE_2* Saper.getSize().y),
    { static_cast <float>(MEMU_BOX_W_S * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S2 * Saper.getSize().y) },
    { static_cast <float>(MENU_BOX_W_P2 * Saper.getSize().x),static_cast <float>(0.212 * Saper.getSize().y) })),

lifebuoy(new Texts(font, "Bomb for time", static_cast<int>(CHAR_SIZE_2* Saper.getSize().y),
    { static_cast <float>(MEMU_BOX_W_S * Saper.getSize().x),static_cast <float>(MENU_BOX_H_S2 * Saper.getSize().y) },
    { static_cast <float>(MENU_BOX_W_P2 * Saper.getSize().x),static_cast <float>(0.305 * Saper.getSize().y) })),

win(new sf::RectangleShape({ static_cast <float>(Saper.getSize().x), 
    static_cast <float>(2 * Saper.getSize().y) })),

lost(new sf::RectangleShape({ static_cast <float>(0.442 * Saper.getSize().x),
        static_cast <float>(0.694 * Saper.getSize().y) }))
{    
    end_in_game->Center_text();
    reset->Center_text();
    back_to_menu->Center_text();
    lifebuoy->Center_text();
    lv_ea->Center_text();
    lv_me->Center_text();
    lv_ha->Center_text();
    end_in_menu->Center_text();

    win->setOrigin({ static_cast <float>(Saper.getSize().x / 2), static_cast <float>(Saper.getSize().y) });
    win->setPosition({ static_cast<float>(Saper.getSize().x) / 2, static_cast<float>(Saper.getSize().y) / 2 });  
    
    lost->setOrigin({ lost->getSize().x/2, lost->getSize().y/2 });
    lost->setPosition({ static_cast<float>(Saper.getSize().x) / 2, 
        static_cast<float>(Saper.getSize().y) / 2 });   
}
Game::~Game()
{
    delete lv_ea, lv_me, lv_ha, reset, win, lost,
        end_in_game, end_in_menu, back_to_menu, clock, lifebuoy, n_o_flags;

    if (game_map != nullptr) { delete game_map; game_map = nullptr; }
}
void Game::Center_txt(Map* m1,const unsigned int &s)
{
    if (999 - s > 998)
    {
        clock->Center_text();
    }
    else if ((999 - s < 100) && (999 - s > 98))
    {
        clock->Center_text();
    }  
    if (game_map->Get_h_m_b_flagged() == 0)
    {
        n_o_flags->Center_text();
    }
    else if ((game_map->Get_h_m_b_flagged() > 8) && (game_map->Get_h_m_b_flagged() < 11))
    {
        n_o_flags->Center_text();
    }
}
bool Game::Menu_make(sf::Event &event,sf::RenderWindow &Saper)
{
    bool choose_lv{ 0 };

    Saper.draw(*lv_ea);
    Saper.draw(*lv_me);
    Saper.draw(*lv_ha);
    Saper.draw(*end_in_menu);

    if (event.mouseButton.button == sf::Mouse::Left)
    {
        unsigned int mouse_x {static_cast<unsigned int>(event.mouseButton.x) };
        unsigned int mouse_y { static_cast<unsigned int>(event.mouseButton.y) };
        if (lv_ea->Click_on_text_box(mouse_x,mouse_y))
        {
            choose_lv = 1;

            Game_m_w = GAME_M_W_1;
            Game_m_h = GAME_M_H_1;
            Mines_on_map = MINES_ON_M_1;
        }
        else if (lv_me->Click_on_text_box(mouse_x, mouse_y))
        {
            choose_lv = 1;
            Game_m_w = GAME_M_W_2;
            Game_m_h = GAME_M_H_2;
            Mines_on_map = MINES_ON_M_2;
            
        }
        else if (lv_ha->Click_on_text_box(mouse_x, mouse_y))
        {
            choose_lv = 1;
            Game_m_w = GAME_M_W_3;
            Game_m_h = GAME_M_H_3;
            Mines_on_map = MINES_ON_M_3;
            
        }
        else if (end_in_menu->Click_on_text_box(mouse_x, mouse_y))
        {
            Saper.close();
        }
        if (choose_lv)
        {
            game_map = new Map(Game_m_w, Game_m_h,Mines_on_map, Saper);
            game_map = game_map->Append_mines_add_val(game_map);   
            start = std::clock();
        }
    }
    return std::move(choose_lv);
}
bool Game::Game_make(sf::Event& event, sf::RenderWindow& Saper)
{ 
    bool choose_lv{ 1 };

    clock->Set_text("Time: " + std::to_string(TIME_FOR_GAME - secounds));
    n_o_flags->Set_text(std::to_string(game_map->Get_h_m_flagged()) + "/" + std::to_string(game_map->Get_h_m_mines()));

    Center_txt(game_map, secounds);
    // lost
    if (TIME_FOR_GAME - secounds == 1)
    {
        game_map->Show_boombs();
        game_map->Set_lost_b(1);
    }
    else if ((!(game_map->Get_win_b())) && (!(game_map->Get_lost_b())))
    {
        secounds = (std::clock() - start) / CLOCKS_PER_SEC; 
        secounds += taken_time;
    }
    Saper.draw(*reset);
    Saper.draw(*end_in_game);
    Saper.draw(*back_to_menu);
    Saper.draw(*clock);
    Saper.draw(*n_o_flags);
    Saper.draw(*lifebuoy);
   
    if (event.type == event.MouseButtonPressed)
    {
        unsigned int mouse_x{ static_cast<unsigned int>(event.mouseButton.x) };
        unsigned int mouse_y{ static_cast<unsigned int>(event.mouseButton.y) };
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (reset->Click_on_text_box(mouse_x, mouse_y))
            {
                delete game_map;
                game_map = nullptr;
                game_map = new Map(Game_m_w, Game_m_h, Mines_on_map, Saper);
                taken_time = 0;
                start = std::clock();
                secounds = 0;
                show_one_bomb = 1;
                game_map = game_map->Append_mines_add_val(game_map);
            }
            if (end_in_game->Click_on_text_box(mouse_x, mouse_y))
            {
                Saper.close();
            }
            if (back_to_menu->Click_on_text_box(mouse_x, mouse_y))
            {
                if (game_map != nullptr) { delete game_map; game_map = nullptr; };
                return 0;
            }
            if (!game_map->Get_win_b() && !game_map->Get_lost_b() && show_one_bomb && lifebuoy->Click_on_text_box(mouse_x, mouse_y))
            {
                if ((secounds + taken_time + TIME_FOR_BOMB < TIME_FOR_GAME - TIME_FOR_BOMB * 2) && (game_map->Get_h_m_b_flagged() < game_map->Get_h_m_mines() - 2))
                {
                    if (game_map->Show_one_bomb())
                    {
                        show_one_bomb = 0;
                        taken_time += TIME_FOR_BOMB;
                    }
                }
            }
        }
        if (!game_map->Get_win_b() && !game_map->Get_lost_b() && game_map->Click_on_map(mouse_x, mouse_y))
        {
            game_map->Click_handle(mouse_x, mouse_y, Saper, event);
        }
    }   
    game_map->Draw_boxes(Saper, game_map);
    
    if (game_map->Get_win_b())
    {
        win->setTexture(&game_map->texturs[13]);
        Saper.draw(*win);
    }
    else if (game_map->Get_lost_b())
    {
        lost->setTexture(&game_map->texturs[12]);
        Saper.draw(*lost);
    }
    return std::move(choose_lv);
}