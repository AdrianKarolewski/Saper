#include "Game.h"
#include "Map.h"
#include "Box.h"
#include "Texts.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include <Windows.h>

Game::Game(sf::RenderWindow &Saper)
{
    if (!font.loadFromFile("Arial.ttf")) { std::cout << "Error font add";}
    window_w = Saper.getSize().x;
    window_h = Saper.getSize().y;
    lv_ea = new Texts(font, "Lv_easy", { 0, 0, 255 }, 50, { static_cast<float>(window_w / 2) - 100,315.f }, { 300.f,100.f }, { static_cast<float>(window_w / 2),350.f });
    lv_me = new Texts(font, "Lv_medium", { 0, 0, 255 }, 50, { static_cast<float>(window_w / 2) - 130,465.f }, { 300.f,100.f }, { static_cast<float>(window_w / 2),500.f });
    lv_ha = new Texts(font, "Lv_hard", { 0, 0, 255 }, 50, { static_cast<float>(window_w / 2) - 100,615.f }, { 300.f,100.f }, { static_cast<float>(window_w / 2),650.f });
    reset = new Texts(font, "Reset", { 0,0,255 }, 50, { static_cast<float>(window_w) - 300,50 }, { 200.f,80.f }, { static_cast<float>(window_w) - 230, 80 });
    win = new Texts(font, "Wygrana", { 0,0,255 }, 50, { static_cast<float>(window_w) - 300,50 }, { 200.f,80.f }, { static_cast<float>(window_w) - 230, 80 });
    lost = new Texts(font, "Przegrana", { 0,0,255 }, 50, { static_cast<float>(window_w) - 300,50 }, { 200.f,80.f }, { static_cast<float>(window_w) - 230, 80 });

}
Game::~Game()
{
    delete lv_ea ,lv_me, lv_ha,
  
    delete Game_m_h, Game_m_w, Mines_on_map;
    if (game_map != nullptr) { delete game_map; }
}
bool Game::menu(sf::Event &event,sf::RenderWindow &Saper)
{
    bool choose_lv = 0;
    Saper.draw(*lv_ea);
    Saper.draw(*lv_me);
    Saper.draw(*lv_ha);
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        if ((event.mouseButton.x > window_w / 2 - 150.f) && (event.mouseButton.x < window_w / 2 + 150.f))
        {
            if ((event.mouseButton.y > 300) && (event.mouseButton.y < 400))
            {
                choose_lv = 1;
                *Game_m_w = 10;
                *Game_m_h = 16;
                *Mines_on_map = 30;
            }
            else if ((event.mouseButton.y > 450) && (event.mouseButton.y < 550))
            {
                choose_lv = 1;
                *Game_m_w = 20;
                *Game_m_h = 30;
                *Mines_on_map = 90;
            }
            else if ((event.mouseButton.y > 600) && (event.mouseButton.y < 700))
            {
                choose_lv = 1;
                *Game_m_w = 40;
                *Game_m_h = 30;
                *Mines_on_map = 200;
            }
        }
        if (choose_lv)
        {
            game_map = new Map(*Game_m_w, *Game_m_h, *Mines_on_map);
            game_map = game_map->append_mines_add_val(game_map);
            game_map->write_map();
        }
    }
    return choose_lv;
}
bool Game::game(sf::Event& event, sf::RenderWindow& Saper)
{
    
    long long* click_x = new long long, * click_y = new long long;
    bool choose_lv = 1;

    Saper.draw(*reset);
    game_map->draw_boxes(Saper, game_map);
    if (game_map->Is_win())
    {

    }
    else if (event.type == sf::Event::MouseButtonPressed)
    {
        *click_x = ((event.mouseButton.x + static_cast<long long>(30 * game_map->map_w / 2) - (window_w / 2))) / 30;
        *click_y = ((event.mouseButton.y + static_cast<long long>(30 * game_map->map_h / 2) - (window_h / 2))) / 30;

        if (!((*click_x > (game_map->map_w - 1)) || (*click_y > (game_map->map_h - 1))) && (!(*click_x < 0 || *click_y < 0)))
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                if (!game_map->t_boxes[*click_y][*click_x].is_block_b())
                {
                    game_map = game_map->flagged_box(*click_x, *click_y, game_map);
                }
            }
            if (event.mouseButton.button == sf::Mouse::Middle)
            {
                if (game_map->t_boxes[*click_y][*click_x].is_flagged_b())
                {
                    game_map = game_map->un_flagged_box(*click_x, *click_y, game_map);
                }
            }
            if (game_map->Is_win())
            {

            }
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if ((!game_map->t_boxes[*click_y][*click_x].is_block_b())
                    && (!game_map->t_boxes[*click_y][*click_x].is_flagged_b()))
                {
                    if (game_map->show_box(*click_x, *click_y))
                    {
                        delete game_map;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < game_map->map_h; i++)
    {
        for (int j = 0; j < game_map->map_w; j++)
        {
            if (game_map->t_boxes[i][j].is_show_it() == 1)
            {
                game_map->show_box(j, i);
            }
        }
    }
    delete click_x, click_y;
    return choose_lv;
}