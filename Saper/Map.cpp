#include "Map.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include <Windows.h>
#include "Box.h"
int random(unsigned int max)
{
	unsigned int digit = rand() % max;
	return digit;
}
Map::Map(unsigned int m_w, unsigned int m_h, unsigned int c_mi, unsigned int h_m_falgged, bool i_win)
	: map_w(m_w),map_h(m_h),c_mines(c_mi)
{
	how_much_flagged = h_m_falgged;
	is_win = i_win;
	// rezerwacja miejsca w pamiêci na boxy
	t_boxes = new Box * [map_h];
	
	for (unsigned int i = 0; i < map_h; i++)
	{
		t_boxes[i] = new Box[map_w];
	}
	texturs = new sf::Texture[11];
	if (!texturs[0].loadFromFile("Texturs/clear.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[1].loadFromFile("Texturs/one.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[2].loadFromFile("Texturs/two.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[3].loadFromFile("Texturs/three.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[4].loadFromFile("Texturs/four.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[5].loadFromFile("Texturs/five.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[6].loadFromFile("Texturs/six.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[7].loadFromFile("Texturs/seven.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[8].loadFromFile("Texturs/eight.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[9].loadFromFile("Texturs/bomb.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
	if (!texturs[10].loadFromFile("Texturs/flag.png"))
	{
		std::cout << "B³¹d wczytania textur";
	}
}
Map::~Map()
{
	// czyszczenie zarezerwowanego miejsca na matrix boxów
	for (unsigned int i = 0; i < map_h; i++)
	{
		delete[] t_boxes[i];
	}
	delete[] t_boxes;
	delete[] texturs;
}
void Map::write_map()
{
	std::cout << map_w << std::endl;
	std::cout << map_h << std::endl;
	std::cout << c_mines << std::endl;
	std::cout << how_much_flagged << std::endl;
	std::cout << is_win << std::endl;
	for (unsigned int i = 0; i < map_h; i++)
	{
		for (unsigned int j = 0; j < map_w; j++)
		{
			std::cout<<t_boxes[i][j].value <<" ";
		}
		std::cout << std::endl;
	}
}
Map* Map::update_val_box(Map* map1, unsigned int x, unsigned int y)
{
	if ((x == 0) && (y == 0))
	{
		if (map1->t_boxes[y + 1][x].value != '*')
		{
			map1->t_boxes[y + 1][x].value++;
		}

		if (map1->t_boxes[y][x + 1].value != '*')
		{
			map1->t_boxes[y][x + 1].value++;
		}

		if (map1->t_boxes[y + 1][x + 1].value != '*')
		{
			map1->t_boxes[y + 1][x + 1].value++;
		}
	}
	else if ((x == 0) && (y == map1->map_h - 1))
	{
		if (map1->t_boxes[y - 1][x].value != '*')
		{
			map1->t_boxes[y - 1][x].value++;
		}
		if (map1->t_boxes[y][x + 1].value != '*')
		{
			map1->t_boxes[y][x + 1].value++;
		}
		if (map1->t_boxes[y - 1][x + 1].value != '*')
		{
			map1->t_boxes[y - 1][x + 1].value++;
		}
	}
	else if ((x == map1->map_w - 1) && (y == 0))
	{
		if (map1->t_boxes[y + 1][x - 1].value != '*')
		{
			map1->t_boxes[y + 1][x - 1].value++;
		}
		if (map1->t_boxes[y][x - 1].value != '*')
		{
			map1->t_boxes[y][x - 1].value++;
		}
		if (map1->t_boxes[y + 1][x].value != '*')
		{
			map1->t_boxes[y + 1][x].value++;
		}
	}
	else if ((x == map1->map_w - 1) && (y == map1->map_h - 1))
	{
		if (map1->t_boxes[y - 1][x - 1].value != '*')
		{
			map1->t_boxes[y - 1][x - 1].value++;
		}
		if (map1->t_boxes[y][x - 1].value != '*')
		{
			map1->t_boxes[y][x - 1].value++;
		}
		if (map1->t_boxes[y - 1][x].value != '*')
		{
			map1->t_boxes[y - 1][x].value++;
		}
	}
	else if (x == 0)
	{
		if (map1->t_boxes[y + 1][x].value != '*')
		{
			map1->t_boxes[y + 1][x].value++;
		}
		if (map1->t_boxes[y - 1][x].value != '*')
		{
			map1->t_boxes[y - 1][x].value++;
		}
		if (map1->t_boxes[y + 1][x + 1].value != '*')
		{
			map1->t_boxes[y + 1][x + 1].value++;
		}
		if (map1->t_boxes[y - 1][x + 1].value != '*')
		{
			map1->t_boxes[y - 1][x + 1].value++;
		}
		if (map1->t_boxes[y][x + 1].value != '*')
		{
			map1->t_boxes[y][x + 1].value++;
		}
	}
	else if (x == map1->map_w - 1)
	{
		if (map1->t_boxes[y + 1][x].value != '*')
		{
			map1->t_boxes[y + 1][x].value++;
		}
		if (map1->t_boxes[y - 1][x].value != '*')
		{
			map1->t_boxes[y - 1][x].value++;
		}
		if (map1->t_boxes[y + 1][x - 1].value != '*')
		{
			map1->t_boxes[y + 1][x - 1].value++;
		}
		if (map1->t_boxes[y - 1][x - 1].value != '*')
		{
			map1->t_boxes[y - 1][x - 1].value++;
		}
		if (map1->t_boxes[y][x - 1].value != '*')
		{
			map1->t_boxes[y][x - 1].value++;
		}
	}
	else if (y == 0)
	{
		if (map1->t_boxes[y][x + 1].value != '*')
		{
			map1->t_boxes[y][x + 1].value++;
		}
		if (map1->t_boxes[y][x - 1].value != '*')
		{
			map1->t_boxes[y][x - 1].value++;
		}
		if (map1->t_boxes[y + 1][x + 1].value != '*')
		{
			map1->t_boxes[y + 1][x + 1].value++;
		}
		if (map1->t_boxes[y + 1][x - 1].value != '*')
		{
			map1->t_boxes[y + 1][x - 1].value++;
		}
		if (map1->t_boxes[y + 1][x].value != '*')
		{
			map1->t_boxes[y + 1][x].value++;
		}
	}
	else if (y == map1->map_h - 1)
	{
		if (map1->t_boxes[y][x + 1].value != '*')
		{
			map1->t_boxes[y][x + 1].value++;
		}
		if (map1->t_boxes[y][x - 1].value != '*')
		{
			map1->t_boxes[y][x - 1].value++;
		}
		if (map1->t_boxes[y - 1][x + 1].value != '*')
		{
			map1->t_boxes[y - 1][x + 1].value++;
		}
		if (map1->t_boxes[y - 1][x - 1].value != '*')
		{
			map1->t_boxes[y - 1][x - 1].value++;
		}
		if (map1->t_boxes[y - 1][x].value != '*')
		{
			map1->t_boxes[y - 1][x].value++;
		}
	}
	else
	{
		if (map1->t_boxes[y - 1][x - 1].value != '*')
		{
			map1->t_boxes[y - 1][x - 1].value++;
		}
		if (map1->t_boxes[y][x - 1].value != '*')
		{
			map1->t_boxes[y][x - 1].value++;
		}
		if (map1->t_boxes[y + 1][x - 1].value != '*')
		{
			map1->t_boxes[y + 1][x - 1].value++;
		}
		if (map1->t_boxes[y - 1][x + 1].value != '*')
		{
			map1->t_boxes[y - 1][x + 1].value++;
		}
		if (map1->t_boxes[y][x + 1].value != '*')
		{
			map1->t_boxes[y][x + 1].value++;
		}
		if (map1->t_boxes[y + 1][x + 1].value != '*')
		{
			map1->t_boxes[y + 1][x + 1].value++;
		}
		if (map1->t_boxes[y - 1][x].value != '*')
		{
			map1->t_boxes[y - 1][x].value++;
		}
		if (map1->t_boxes[y + 1][x].value != '*')
		{
			map1->t_boxes[y + 1][x].value++;
		}
	}
	return map1;
}
Map* Map::append_mines_add_val(Map * map1)
{
	int i = 0, j = 0;
	for (unsigned int k = 0; k < map1->c_mines; k++)
	{
		i = random(map1->map_h);
		j = random(map1->map_w);
		while (map1->t_boxes[i][j].is_mine)
		{
			i = random(map1->map_h);
			j = random(map1->map_w);
		}
		map1->t_boxes[i][j].is_mine = 1;
		map1->t_boxes[i][j].value = '*';
		update_val_box(map1, j, i);
	}
	
	return map1;
}
Map* Map::draw_boxes(sf::RenderWindow &window_sap, Map* map1)
{
	int window_w = window_sap.getSize().x, window_h = window_sap.getSize().y;
	sf::Vector2f vector_position{ (window_w/2) - (t_boxes[0][0].size_box.x * map_w)/2, (window_h / 2) - (t_boxes[0][0].size_box.y * map_h)/2 };
	
	for (unsigned int i = 0; i < map_h; i++)
	{
		for (unsigned int j = 0; j < map_w; j++)
		{
			
			t_boxes[i][j].box_view.setPosition(vector_position);
			window_sap.draw(t_boxes[i][j]);
			vector_position.x += t_boxes[0][0].size_box.x;
		}
		vector_position.x = (window_w / 2) - (t_boxes[0][0].size_box.x * map_w) / 2;
		vector_position.y += t_boxes[0][0].size_box.y;
	}
	return map1;
}
// zwraca wartoœc elementu
bool Map::Is_win()
{
	return how_much_flagged == c_mines ?  true :  false;
}
// zmienia wartosc elementu i j¹ zwraca
bool Map::Is_win(bool change)
{
	is_win = change;
	return is_win;
}
unsigned int Map::get_how_much_flagged()
{
	return how_much_flagged;
}
Map* Map::flagged_box(const unsigned int x, const unsigned int y,Map * map1)
{
	
	t_boxes[y][x].box_view.setTexture(&texturs[10]);
	t_boxes[y][x].is_block = 1;
	t_boxes[y][x].is_flagged = 1;
	how_much_flagged++;
	return map1;
}
Map* Map::un_flagged_box(const unsigned int x, const unsigned int y, Map* map1)
{
	t_boxes[y][x].box_view.setTexture(NULL);
	t_boxes[y][x].is_block = 0;
	t_boxes[y][x].is_flagged = 0;
	how_much_flagged--;
	return map1;
}
void Map::add_to_show(unsigned int y, unsigned int x)
{
	if ((x == 0) && (y == 0))
	{
		if (t_boxes[y + 1][x].value != '*')
		{
			t_boxes[y + 1][x].show_it = 1;
		}

		if (t_boxes[y][x + 1].value != '*')
		{
			t_boxes[y][x + 1].show_it = 1;
		}

		if (t_boxes[y + 1][x + 1].value != '*')
		{
			t_boxes[y + 1][x + 1].show_it = 1;
		}
	}
	else if ((x == 0) && (y == map_h - 1))
	{
		if (t_boxes[y - 1][x].value != '*')
		{
			t_boxes[y - 1][x].show_it = 1;
		}
		if (t_boxes[y][x + 1].value != '*')
		{
			t_boxes[y][x + 1].show_it = 1;
		}
		if (t_boxes[y - 1][x + 1].value != '*')
		{
			t_boxes[y - 1][x + 1].show_it = 1;
		}



	}
	else if ((x == map_w - 1) && (y == 0))
	{
		if (t_boxes[y + 1][x - 1].value != '*')
		{
			t_boxes[y + 1][x - 1].show_it = 1;
		}
		if (t_boxes[y][x - 1].value != '*')
		{
			t_boxes[y][x - 1].show_it = 1;
		}
		if (t_boxes[y + 1][x].value != '*')
		{
			t_boxes[y + 1][x].show_it = 1;
		}
	}
	else if ((x == map_w - 1) && (y == map_h - 1))
	{
		if (t_boxes[y - 1][x - 1].value != '*')
		{
			t_boxes[y - 1][x - 1].show_it = 1;
		}
		if (t_boxes[y][x - 1].value != '*')
		{
			t_boxes[y][x - 1].show_it = 1;
		}
		if (t_boxes[y - 1][x].value != '*')
		{
			t_boxes[y - 1][x].show_it = 1;
		}



	}
	else if (x == 0)
	{
		if (t_boxes[y + 1][x].value != '*')
		{
			t_boxes[y + 1][x].show_it = 1;
		}
		if (t_boxes[y - 1][x].value != '*')
		{
			t_boxes[y - 1][x].show_it = 1;
		}
		if (t_boxes[y + 1][x + 1].value != '*')
		{
			t_boxes[y + 1][x + 1].show_it = 1;
		}
		if (t_boxes[y - 1][x + 1].value != '*')
		{
			t_boxes[y - 1][x + 1].show_it = 1;
		}
		if (t_boxes[y][x + 1].value != '*')
		{
			t_boxes[y][x + 1].show_it = 1;
		}
	}
	else if (x == map_w - 1)
	{
		if (t_boxes[y + 1][x].value != '*')
		{
			t_boxes[y + 1][x].show_it = 1;
		}
		if (t_boxes[y - 1][x].value != '*')
		{
			t_boxes[y - 1][x].show_it = 1;
		}
		if (t_boxes[y + 1][x - 1].value != '*')
		{
			t_boxes[y + 1][x - 1].show_it = 1;
		}
		if (t_boxes[y - 1][x - 1].value != '*')
		{
			t_boxes[y - 1][x - 1].show_it = 1;
		}
		if (t_boxes[y][x - 1].value != '*')
		{
			t_boxes[y][x - 1].show_it = 1;
		}
	}
	else if (y == 0)
	{
		if (t_boxes[y][x + 1].value != '*')
		{
			t_boxes[y][x + 1].show_it = 1;
		}
		if (t_boxes[y][x - 1].value != '*')
		{
			t_boxes[y][x - 1].show_it = 1;
		}
		if (t_boxes[y + 1][x + 1].value != '*')
		{
			t_boxes[y + 1][x + 1].show_it = 1;
		}
		if (t_boxes[y + 1][x - 1].value != '*')
		{
			t_boxes[y + 1][x - 1].show_it = 1;
		}
		if (t_boxes[y + 1][x].value != '*')
		{
			t_boxes[y + 1][x].show_it = 1;
		}
	}
	else if (y == map_h - 1)
	{
		if (t_boxes[y][x + 1].value != '*')
		{
			t_boxes[y][x + 1].show_it = 1;
		}
		if (t_boxes[y][x - 1].value != '*')
		{
			t_boxes[y][x - 1].show_it = 1;
		}
		if (t_boxes[y - 1][x + 1].value != '*')
		{
			t_boxes[y - 1][x + 1].show_it = 1;
		}
		if (t_boxes[y - 1][x - 1].value != '*')
		{
			t_boxes[y - 1][x - 1].show_it = 1;
		}
		if (t_boxes[y - 1][x].value != '*')
		{
			t_boxes[y - 1][x].show_it = 1;
		}
	}
	else
	{
		if (t_boxes[y - 1][x - 1].value != '*')
		{
			t_boxes[y - 1][x - 1].show_it = 1;
		}
		if (t_boxes[y][x - 1].value != '*')
		{
			t_boxes[y][x - 1].show_it = 1;
		}
		if (t_boxes[y + 1][x - 1].value != '*')
		{
			t_boxes[y + 1][x - 1].show_it = 1;
		}
		if (t_boxes[y - 1][x + 1].value != '*')
		{
			t_boxes[y - 1][x + 1].show_it = 1;
		}
		if (t_boxes[y][x + 1].value != '*')
		{
			t_boxes[y][x + 1].show_it = 1;
		}
		if (t_boxes[y + 1][x + 1].value != '*')
		{
			t_boxes[y + 1][x + 1].show_it = 1;
		}
		if (t_boxes[y - 1][x].value != '*')
		{
			t_boxes[y - 1][x].show_it = 1;
		}
		if (t_boxes[y + 1][x].value != '*')
		{
			t_boxes[y + 1][x].show_it = 1;
		}
	}
}
bool Map::show_box(const unsigned int x, const unsigned int y)
{
	t_boxes[y][x].is_block = 1;
	t_boxes[y][x].show_it = 0;
	switch (t_boxes[y][x].value)
	{
	case '0':
		t_boxes[y][x].box_view.setTexture(&texturs[0]);
		add_to_show(y, x);
		break;
	case '1':
		t_boxes[y][x].box_view.setTexture(&texturs[1]);
		break;
	case '2':
		t_boxes[y][x].box_view.setTexture(&texturs[2]);
		break;
	case '3':
		t_boxes[y][x].box_view.setTexture(&texturs[3]);
		break;
	case '4':
		t_boxes[y][x].box_view.setTexture(&texturs[4]);
		break;
	case '5':
		t_boxes[y][x].box_view.setTexture(&texturs[5]);
		break;
	case '6':
		t_boxes[y][x].box_view.setTexture(&texturs[6]);
		break;
	case '7':
		t_boxes[y][x].box_view.setTexture(&texturs[7]);
		break;
	case '8':
		t_boxes[y][x].box_view.setTexture(&texturs[8]);
		break;
	case '*':
		t_boxes[y][x].box_view.setTexture(&texturs[9]);
		break;
	}
	return t_boxes[y][x].is_mine;
}
