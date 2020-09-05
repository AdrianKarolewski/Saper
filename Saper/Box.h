#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include <Windows.h>
#include "Box.h"

class Box : public sf::Drawable
{
	char value;
	bool is_mine, is_block, is_flagged, show_it;
	sf::RectangleShape box_view;
	friend class Map;
	
public:
	Box(char val = '0', bool is_m = 0, bool is_b = 0, bool is_fl = 0, bool show_i = 0);
	
	~Box();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	bool is_block_b();
	bool is_flagged_b();
	bool is_show_it();
};

