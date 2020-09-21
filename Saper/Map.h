#pragma once

#include "Box.h"

class Map
{
	unsigned int how_much_bombs_flagged = 0;
	unsigned int how_much_put_flags = 0;
	bool win_b = 0, lost_b = 0;
	friend class Game;
	sf::Texture *texturs;
	Box** t_boxes = nullptr;

public:
	const unsigned int map_w, map_h, c_mines;
	
	Map(unsigned int &m_w, unsigned int &m_h, unsigned int &c_mi, sf::RenderWindow& Saper);
	~Map();

	Map* append_mines_add_val(Map * map1);
	Map* update_val_box(Map* map1,const unsigned int &x, const unsigned int &y);
	Map* draw_boxes(sf::RenderWindow &window_sap,Map* map1);

	void flagged_box(const unsigned int &x, const unsigned int &y);
	void un_flagged_box(const unsigned int &x, const unsigned int &y);
	void add_to_show(const unsigned int &y,const unsigned int &x);
	void show_boombs();
	void show_one_bomb();
	void click_handle(const unsigned int& x, const unsigned int& y, sf::RenderWindow& Saper, sf::Event event);

	bool show_box(const unsigned int& x, const unsigned int& y);
	bool click_on_map(const unsigned int &x, const unsigned int &y);
	bool Is_win();
	
};

