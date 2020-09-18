#pragma once

#include "Box.h"

class Map
{
	unsigned int how_much_flagged = 0;
	bool win_b = 0, lost_b = 0;
	friend class Game;
	sf::Texture *texturs;
	Box** t_boxes = nullptr;

public:
	const unsigned int map_w, map_h, c_mines;
	

	Map(unsigned int &m_w, unsigned int &m_h, unsigned int &c_mi, sf::RenderWindow& Saper);
	~Map();

	bool Is_win();
	Map* append_mines_add_val(Map * map1);
	Map* update_val_box(Map* map1,const unsigned int &x, const unsigned int &y);
	Map* draw_boxes(sf::RenderWindow &window_sap,Map* map1);
	Map* flagged_box(const unsigned int &x, const unsigned int &y, Map* map1);
	Map* un_flagged_box(const unsigned int &x, const unsigned int &y, Map* map1);
	bool show_box(const unsigned int &x, const unsigned int &y);
	void add_to_show(const unsigned int &y,const unsigned int &x);
	void show_boombs();
	bool click_on_map(const unsigned int &x, const unsigned int &y);
};

