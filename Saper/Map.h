#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include <Windows.h>
#include "Box.h"

class Map
{
	unsigned int how_much_flagged = 0;
	bool is_win = 0;
	friend class Game;
	sf::Texture *texturs;

public:
	const unsigned int map_w, map_h, c_mines;
	Box** t_boxes = nullptr;

	Map(unsigned int m_w, unsigned int m_h, unsigned int c_mi, sf::RenderWindow& Saper, unsigned int h_m_falgged = 0, bool is_win = 0);
	~Map();

	bool Is_win();
	
	bool Is_win(bool change);

	Map* append_mines_add_val(Map * map1);
	Map* update_val_box(Map* map1, unsigned int x, unsigned int y);
	Map* draw_boxes(sf::RenderWindow &window_sap,Map* map1);
	Map* flagged_box(const unsigned int x, const unsigned int y, Map* map1);
	Map* un_flagged_box(const unsigned int x, const unsigned int y, Map* map1);
	bool show_box(const unsigned int x, const unsigned int y);
	void add_to_show(unsigned int y, unsigned int x);
	unsigned int get_how_much_flagged();
	bool click_on_map(const unsigned int &x, const unsigned int &y);
	
};

