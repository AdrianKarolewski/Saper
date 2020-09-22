#include "Map.h"
#include "Box.h"
#include <iostream>
int random(unsigned int max)
{
	unsigned int digit = rand() % max;
	return digit;
}
Map::Map(unsigned int &m_w, unsigned int &m_h, unsigned int &c_mi, sf::RenderWindow& Saper)
	: map_w(m_w),map_h(m_h),c_mines(c_mi)
{
	// rezerwacja miejsca w pamiêci na boxy
	t_boxes = new Box * [map_h];
	
	for (unsigned int i = 0; i < map_h; i++)
	{
		t_boxes[i] = new Box[map_w];
	}
	int window_w = Saper.getSize().x, window_h = Saper.getSize().y;
	for (int i = 0; i < map_h; i++)
	{
		for (int j = 0; j < map_w; j++)
		{
			t_boxes[i][j].box_view.setSize({ static_cast<float>(0.015625 * window_w),static_cast<float>(0.015625 * window_w) });
			t_boxes[i][j].size_box = { t_boxes[i][j].box_view.getSize().x,t_boxes[i][j].box_view.getSize().y };
		}
	}
	//ustawienie boxów
	
	int x_push = t_boxes[0][0].box_view.getSize().x;
	int y_push = t_boxes[0][0].box_view.getSize().y;

	sf::Vector2f vector_position{ static_cast<float>((window_w / 2) - (x_push * map_w) / 2), static_cast<float>((window_h / 2) - (y_push * map_h) / 2) };

	for (unsigned int i = 0; i < map_h; i++)
	{
		for (unsigned int j = 0; j < map_w; j++)
		{
			t_boxes[i][j].box_view.setPosition(vector_position);
			vector_position.x += x_push;
		}
		vector_position.x = static_cast<float>((window_w / 2) - (x_push * map_w) / 2);
		vector_position.y += static_cast<float>(y_push);
	}
	///////////////////////
	texturs = new sf::Texture[14];
	if (!texturs[0].loadFromFile("Texturs/clear.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[1].loadFromFile("Texturs/one.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[2].loadFromFile("Texturs/two.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[3].loadFromFile("Texturs/three.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[4].loadFromFile("Texturs/four.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[5].loadFromFile("Texturs/five.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[6].loadFromFile("Texturs/six.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[7].loadFromFile("Texturs/seven.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[8].loadFromFile("Texturs/eight.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[9].loadFromFile("Texturs/bomb.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[10].loadFromFile("Texturs/flag.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[11].loadFromFile("Texturs/bombX.png")) { std::cout << "B³¹d wczytania textur"; }
	
	if (!texturs[12].loadFromFile("Texturs/end_boom.png")) { std::cout << "B³¹d wczytania textur";}
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
Map* Map::update_val_box(Map* map1, const unsigned int &x, const unsigned int &y)
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
	for (unsigned int i = 0; i < map_h; i++)
	{
		for (unsigned int j = 0; j < map_w; j++)
		{
			window_sap.draw(t_boxes[i][j]);
		}
	}
	return map1;
}

void Map::flagged_box(const unsigned int& x, const unsigned int& y)
{
	t_boxes[y][x].box_view.setTexture(&texturs[10]);
	t_boxes[y][x].is_block = 1;
	t_boxes[y][x].is_flagged = 1;
	how_much_put_flags++;
	if (t_boxes[y][x].is_mine) { how_much_bombs_flagged++; }
}
void Map::un_flagged_box(const unsigned int& x, const unsigned int& y)
{
	t_boxes[y][x].box_view.setTexture(NULL);
	t_boxes[y][x].is_block = 0;
	t_boxes[y][x].is_flagged = 0;
	how_much_put_flags--;
	if (t_boxes[y][x].is_mine) { how_much_bombs_flagged--; }

}
void Map::add_to_show(const unsigned int& y, const unsigned int& x)
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
void Map::show_boombs()
{
	for (int i = 0; i < map_h; i++)
	{
		for (int j = 0; j < map_w; j++)
		{
			t_boxes[i][j].is_block = 1;
			if ((t_boxes[i][j].is_mine) && !(t_boxes[i][j].is_flagged))
			{
				t_boxes[i][j].box_view.setTexture(&texturs[9]);
			}
		}
	}
}
void Map::show_one_bomb()
{
	for (int i = random(map_h) - 1; i < map_h; i++)
	{
		for (int j = random(map_w) - 1; j < map_w; j++)
		{
			if ((t_boxes[i][j].is_mine) && (!t_boxes[i][j].is_flagged))
			{
				t_boxes[i][j].is_block = 1;
				t_boxes[i][j].show_it = 0;
				t_boxes[i][j].box_view.setTexture(&texturs[11]);
				how_much_bombs_flagged += 1;
				return;
			}
		}
	}
}
void Map::click_handle(const unsigned int& x, const unsigned int& y, sf::RenderWindow& Saper, sf::Event event)
{
	long long* click_x = new long long, * click_y = new long long;
	// obliczanie indexów tablicy boxów
	*click_x = ((x + static_cast<long long>(t_boxes[0][0].size_box.x * map_w / 2) - (Saper.getSize().x / 2))) / t_boxes[0][0].size_box.x;
	*click_y = ((y + static_cast<long long>(t_boxes[0][0].size_box.y * map_h / 2) - (Saper.getSize().y / 2))) / t_boxes[0][0].size_box.y;
	//oflagowanie boxa
	if (event.mouseButton.button == sf::Mouse::Right)
	{
		if (!t_boxes[*click_y][*click_x].is_block_b())
		{
			flagged_box(*click_x, *click_y);
		}
	}
	if (Is_win())
	{
		win_b = 1;
	}
	if (event.mouseButton.button == sf::Mouse::Middle)
	{
		if (t_boxes[*click_y][*click_x].is_flagged_b())
		{
			un_flagged_box(*click_x, *click_y);
		}
	}
	// otwieranie boxa
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		if (!(t_boxes[*click_y][*click_x].is_block_b())
			&& (!t_boxes[*click_y][*click_x].is_flagged_b()))
		{
			// przegrana
			if (show_box(*click_x, *click_y))
			{
				show_boombs();
				lost_b = 1;
			}
		}
	}
	for (int i = 0; i < map_h; i++)
	{
		for (int j = 0; j < map_w; j++)
		{
			if (t_boxes[i][j].is_show_it() == 1)
			{
				show_box(j, i);
			}
		}
	}
	delete click_x, click_y;
}

bool Map::Is_win()
{
	if (how_much_bombs_flagged == how_much_put_flags)
	{
		return how_much_bombs_flagged == c_mines ? true : false;
	}
	return 0;
}
bool Map::show_box(const unsigned int &x, const unsigned int &y)
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
bool Map::click_on_map(const unsigned int& x, const unsigned int& y)
{
	if ((x > t_boxes[0][0].box_view.getPosition().x) && (x < t_boxes[map_h-1][map_w-1].box_view.getPosition().x + t_boxes[map_h-1][map_w-1].box_view.getSize().x))
	{
		if ((y > t_boxes[0][0].box_view.getPosition().y) && (y < t_boxes[map_h - 1][map_w - 1].box_view.getPosition().y + t_boxes[map_h - 1][map_w - 1].box_view.getSize().y))
		{
			return 1;
		}
	}
	return 0;
}
