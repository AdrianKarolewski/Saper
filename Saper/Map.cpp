#include "Map.h"
#include "Box.h"
#include <iostream>

int random(unsigned int max)
{
	unsigned int digit = rand() % max;
	return digit;
}
Map::Map(unsigned int &m_w, unsigned int &m_h, unsigned int &c_mi, sf::RenderWindow& Saper)
	: m_map_w(m_w),m_map_h(m_h),m_c_mines(c_mi)
{
	// rezerwacja miejsca w pamiêci na boxy
	t_boxes = new Box ** [m_map_h];
	
	for (unsigned int i = 0; i < m_map_h; i++)
	{
		t_boxes[i] = new Box*[m_map_w];
	}
	int window_w = Saper.getSize().x, window_h = Saper.getSize().y;
	for (int i = 0; i < m_map_h; i++)
	{
		for (int j = 0; j < m_map_w; j++)
		{
			t_boxes[i][j] = new Box({static_cast<float>(0.015625 * window_w),
				static_cast<float>(0.015625 * window_w) });
		}
	}
	//ustawienie boxów
	
	int x_push = t_boxes[0][0]->Get_box_size().x;
	int y_push = t_boxes[0][0]->Get_box_size().y;

	sf::Vector2f vector_position{ static_cast<float>((window_w / 2) - (x_push * m_map_w) / 2), 
		static_cast<float>((window_h / 2) - (y_push * m_map_h) / 2) };

	for (unsigned int i = 0; i < m_map_h; i++)
	{
		for (unsigned int j = 0; j < m_map_w; j++)
		{
			t_boxes[i][j]->Set_position(vector_position);
			vector_position.x += x_push;
		}
		vector_position.x = static_cast<float>((window_w / 2) - (x_push * m_map_w) / 2);
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

	if (!texturs[13].loadFromFile("Texturs/win.png")) { std::cout << "B³¹d wczytania textur"; }
}
Map::~Map()
{
	// czyszczenie zarezerwowanego miejsca na matrix boxów
	if (t_boxes != nullptr)
	{
		for (unsigned int i = 0; i < m_map_h; i++)
		{

			for (unsigned int j = 0; j < m_map_w; j++)
			{
				delete t_boxes[i][j];
			}
			delete[] t_boxes[i];
		}
		delete[] t_boxes;
		t_boxes = nullptr;
	}
	if (texturs != nullptr)
	{
		delete[] texturs;
		texturs = nullptr;
	}
	
	
}
Map* Map::Update_val_box(Map* map1, const unsigned int &x, const unsigned int &y)
{
	if ((x == 0) && (y == 0))
	{
		if (!map1->t_boxes[y + 1][x]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x]->Up_value();
		}

		if (!map1->t_boxes[y][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y][x + 1]->Up_value();
		}

		if (!map1->t_boxes[y + 1][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x + 1]->Up_value();
		}
	}
	else if ((x == 0) && (y == map1->m_map_h - 1))
	{
		if (!map1->t_boxes[y - 1][x]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x]->Up_value();
		}
		if (!map1->t_boxes[y][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x + 1]->Up_value();
		}
	}
	else if ((x == map1->m_map_w - 1) && (y == 0))
	{
		if (!map1->t_boxes[y + 1][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y + 1][x]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x]->Up_value();
		}
	}
	else if ((x == map1->m_map_w - 1) && (y == map1->m_map_h - 1))
	{
		if (!map1->t_boxes[y - 1][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x]->Up_value();
		}
	}
	else if (x == 0)
	{
		if (!map1->t_boxes[y + 1][x]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x]->Up_value();
		}
		if (!map1->t_boxes[y + 1][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y][x + 1]->Up_value();
		}
	}
	else if (x == map1->m_map_w - 1)
	{
		if (!map1->t_boxes[y + 1][x]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x]->Up_value();
		}
		if (!map1->t_boxes[y + 1][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y][x - 1]->Up_value();
		}
	}
	else if (y == 0)
	{
		if (!map1->t_boxes[y][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y][x - 1]->Up_value() ;
		}
		if (!map1->t_boxes[y + 1][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y + 1][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y + 1][x]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x]->Up_value();
		}
	}
	else if (y == map1->m_map_h - 1)
	{
		if (!map1->t_boxes[y][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x]->Up_value();
		}
	}
	else
	{
		if (!map1->t_boxes[y - 1][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y + 1][x - 1]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x - 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y + 1][x + 1]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x + 1]->Up_value();
		}
		if (!map1->t_boxes[y - 1][x]->Is_mine_b())
		{
			map1->t_boxes[y - 1][x]->Up_value();
		}
		if (!map1->t_boxes[y + 1][x]->Is_mine_b())
		{
			map1->t_boxes[y + 1][x]->Up_value();
		}
	}
	return map1;
}
Map* Map::Append_mines_add_val(Map * map1)
{
	int i = 0, j = 0;
	for (unsigned int k = 0; k < map1->m_c_mines; k++)
	{
		i = random(map1->m_map_h);
		j = random(map1->m_map_w);
		while (map1->t_boxes[i][j]->Is_mine_b())
		{
			i = random(map1->m_map_h);
			j = random(map1->m_map_w);
		}
		map1->t_boxes[i][j]->Set_mine(1);
		map1->t_boxes[i][j]->Set_val('*');
		Update_val_box(map1, j, i);
	}
	return map1;
}
Map* Map::Draw_boxes(sf::RenderWindow &window_sap, Map* map1)
{
	for (unsigned int i = 0; i < m_map_h; i++)
	{
		for (unsigned int j = 0; j < m_map_w; j++)
		{
			window_sap.draw(*t_boxes[i][j]);
		}
	}
	return map1;
}
void Map::Flagged_box(const unsigned int& x, const unsigned int& y)
{
	t_boxes[y][x]->Set_tex(texturs[10]);
	t_boxes[y][x]->Set_block(1);
	t_boxes[y][x]->Set_is_flagged(1);
	m_how_much_put_flags++;
	if (t_boxes[y][x]->Is_mine_b()) { m_how_much_bombs_flagged++; }
}
void Map::Un_flagged_box(const unsigned int& x, const unsigned int& y)
{
	t_boxes[y][x]->Clear_tex();
	t_boxes[y][x]->Set_block(0);
	t_boxes[y][x]->Set_is_flagged(0);
	m_how_much_put_flags--;
	if (t_boxes[y][x]->Is_mine_b()) { m_how_much_bombs_flagged--; }
}
void Map::Add_to_show(const unsigned int& y, const unsigned int& x)
{
	if ((x == 0) && (y == 0))
	{
		if (!t_boxes[y + 1][x]->Is_mine_b())
		{
			t_boxes[y + 1][x]->Set_show_it(1);
		}

		if (!t_boxes[y][x + 1]->Is_mine_b())
		{
			t_boxes[y][x + 1]->Set_show_it(1);
		}

		if (!t_boxes[y + 1][x + 1]->Is_mine_b())
		{
			t_boxes[y + 1][x + 1]->Set_show_it(1);
		}
	}
	else if ((x == 0) && (y == m_map_h - 1))
	{
		if (!t_boxes[y - 1][x]->Is_mine_b())
		{
			t_boxes[y - 1][x]->Set_show_it(1);
		}
		if (!t_boxes[y][x + 1]->Is_mine_b())
		{
			t_boxes[y][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x + 1]->Is_mine_b())
		{
			t_boxes[y - 1][x + 1]->Set_show_it(1);
		}
	}
	else if ((x == m_map_w - 1) && (y == 0))
	{
		if (!t_boxes[y + 1][x - 1]->Is_mine_b())
		{
			t_boxes[y + 1][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y][x - 1]->Is_mine_b())
		{
			t_boxes[y][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x]->Is_mine_b())
		{
			t_boxes[y + 1][x]->Set_show_it(1);
		}
	}
	else if ((x == m_map_w - 1) && (y == m_map_h - 1))
	{
		if (!t_boxes[y - 1][x - 1]->Is_mine_b())
		{
			t_boxes[y - 1][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y][x - 1]->Is_mine_b())
		{
			t_boxes[y][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x]->Is_mine_b())
		{
			t_boxes[y - 1][x]->Set_show_it(1);
		}
	}
	else if (x == 0)
	{
		if (!t_boxes[y + 1][x]->Is_mine_b())
		{
			t_boxes[y + 1][x]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x]->Is_mine_b())
		{
			t_boxes[y - 1][x]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x + 1]->Is_mine_b())
		{
			t_boxes[y + 1][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x + 1]->Is_mine_b())
		{
			t_boxes[y - 1][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y][x + 1]->Is_mine_b())
		{
			t_boxes[y][x + 1]->Set_show_it(1);
		}
	}
	else if (x == m_map_w - 1)
	{
		if (!t_boxes[y + 1][x]->Is_mine_b())
		{
			t_boxes[y + 1][x]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x]->Is_mine_b())
		{
			t_boxes[y - 1][x]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x - 1]->Is_mine_b())
		{
			t_boxes[y + 1][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x - 1]->Is_mine_b())
		{
			t_boxes[y - 1][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y][x - 1]->Is_mine_b())
		{
			t_boxes[y][x - 1]->Set_show_it(1);
		}
	}
	else if (y == 0)
	{
		if (!t_boxes[y][x + 1]->Is_mine_b())
		{
			t_boxes[y][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y][x - 1]->Is_mine_b())
		{
			t_boxes[y][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x + 1]->Is_mine_b())
		{
			t_boxes[y + 1][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x - 1]->Is_mine_b())
		{
			t_boxes[y + 1][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x]->Is_mine_b())
		{
			t_boxes[y + 1][x]->Set_show_it(1);
		}
	}
	else if (y == m_map_h - 1)
	{
		if (!t_boxes[y][x + 1]->Is_mine_b())
		{
			t_boxes[y][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y][x - 1]->Is_mine_b())
		{
			t_boxes[y][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x + 1]->Is_mine_b())
		{
			t_boxes[y - 1][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x - 1]->Is_mine_b())
		{
			t_boxes[y - 1][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x]->Is_mine_b())
		{
			t_boxes[y - 1][x]->Set_show_it(1);
		}
	}
	else
	{
		if (!t_boxes[y - 1][x - 1]->Is_mine_b())
		{
			t_boxes[y - 1][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y][x - 1]->Is_mine_b())
		{
			t_boxes[y][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x - 1]->Is_mine_b())
		{
			t_boxes[y + 1][x - 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x + 1]->Is_mine_b())
		{
			t_boxes[y - 1][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y][x + 1]->Is_mine_b())
		{
			t_boxes[y][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x + 1]->Is_mine_b())
		{
			t_boxes[y + 1][x + 1]->Set_show_it(1);
		}
		if (!t_boxes[y - 1][x]->Is_mine_b())
		{
			t_boxes[y - 1][x]->Set_show_it(1);
		}
		if (!t_boxes[y + 1][x]->Is_mine_b())
		{
			t_boxes[y + 1][x]->Set_show_it(1);
		}
	}
}
void Map::Show_boombs()
{
	for (int i = 0; i < m_map_h; i++)
	{
		for (int j = 0; j < m_map_w; j++)
		{
			t_boxes[i][j]->Set_block(1);
			if ((t_boxes[i][j]->Is_mine_b()) && !(t_boxes[i][j]->Is_flagged_b()))
			{
				t_boxes[i][j]->Set_tex(texturs[9]);
			}
		}
	}
}
bool Map::Show_one_bomb()
{
	for (int i = random(m_map_h) - 1; i < m_map_h; i++)
	{
		for (int j = random(m_map_w) - 1; j < m_map_w; j++)
		{
			if ((t_boxes[i][j]->Is_mine_b()) && (!t_boxes[i][j]->Is_flagged_b()))
			{
				t_boxes[i][j]->Set_block(1);
				t_boxes[i][j]->Set_show_it(0);
				t_boxes[i][j]->Set_tex(texturs[11]);
				m_how_much_bombs_flagged += 1;
				m_how_much_put_flags += 1;
				return 1;
			}
			
		}
	}
	return 0;
}
void Map::Click_handle(const unsigned int& x, const unsigned int& y, sf::RenderWindow& Saper, sf::Event event)
{
	long long* click_x = new long long, * click_y = new long long;
	// obliczanie indexów tablicy boxów
	*click_x = ((x + static_cast<long long>(t_boxes[0][0]->Get_box_size().x * m_map_w / 2) - (Saper.getSize().x / 2))) / t_boxes[0][0]->Get_box_size().x;
	*click_y = ((y + static_cast<long long>(t_boxes[0][0]->Get_box_size().y * m_map_h / 2) - (Saper.getSize().y / 2))) / t_boxes[0][0]->Get_box_size().y;
	//oflagowanie boxa
	if (event.mouseButton.button == sf::Mouse::Right)
	{
		if (!t_boxes[*click_y][*click_x]->Is_block_b())
		{
			Flagged_box(*click_x, *click_y);
		}
	}
	if (Is_win())
	{
		m_win_b = 1;
	}
	if (event.mouseButton.button == sf::Mouse::Middle)
	{
		if (t_boxes[*click_y][*click_x]->Is_flagged_b())
		{
			Un_flagged_box(*click_x, *click_y);
		}
	}
	// otwieranie boxa
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		if (!(t_boxes[*click_y][*click_x]->Is_block_b())
			&& (!t_boxes[*click_y][*click_x]->Is_flagged_b()))
		{
			// przegrana
			if (Show_box(*click_x, *click_y))
			{
				Show_boombs();
				m_lost_b = 1;
			}
		}
	}
	for (int i = 0; i < m_map_h; i++)
	{
		for (int j = 0; j < m_map_w; j++)
		{
			if (t_boxes[i][j]->Is_show_it() == 1)
			{
				Show_box(j, i);
			}
		}
	}
	delete click_x, click_y;
}
bool Map::Is_win()
{
	if (m_how_much_bombs_flagged == m_how_much_put_flags)
	{
		return m_how_much_bombs_flagged == m_c_mines ? true : false;
	}
	return 0;
}
bool Map::Show_box(const unsigned int &x, const unsigned int &y)
{
	t_boxes[y][x]->Set_block(1);
	t_boxes[y][x]->Set_show_it(0);
	switch (t_boxes[y][x]->Get_val())
	{
	case '0':
		t_boxes[y][x]->Set_tex(texturs[0]);
		Add_to_show(y, x);
		break;
	case '1':
		t_boxes[y][x]->Set_tex(texturs[1]);
		break;
	case '2':
		t_boxes[y][x]->Set_tex(texturs[2]);
		break;
	case '3':
		t_boxes[y][x]->Set_tex(texturs[3]);
		break;
	case '4':
		t_boxes[y][x]->Set_tex(texturs[4]);
		break;
	case '5':
		t_boxes[y][x]->Set_tex(texturs[5]);
		break;
	case '6':
		t_boxes[y][x]->Set_tex(texturs[6]);
		break;
	case '7':
		t_boxes[y][x]->Set_tex(texturs[7]);
		break;
	case '8':
		t_boxes[y][x]->Set_tex(texturs[8]);
		break;
	case '*':
		t_boxes[y][x]->Set_tex(texturs[9]);
		break;
	}
	return t_boxes[y][x]->Is_mine_b();
}
bool Map::Click_on_map(const unsigned int& x, const unsigned int& y)
{
	if ((x > t_boxes[0][0]->Get_box_pos().x) && (x < t_boxes[m_map_h-1][m_map_w-1]->Get_box_pos().x + t_boxes[m_map_h-1][m_map_w-1]->Get_box_size().x))
	{
		if ((y > t_boxes[0][0]->Get_box_pos().y) && (y < t_boxes[m_map_h - 1][m_map_w - 1]->Get_box_pos().y + t_boxes[m_map_h - 1][m_map_w - 1]->Get_box_size().y))
		{
			return 1;
		}
	}
	return 0;
}
unsigned int Map::Get_h_m_b_flagged() const
{
	return m_how_much_bombs_flagged;
}
unsigned int Map::Get_h_m_flagged() const
{
	return m_how_much_put_flags;
}
const unsigned int Map::Get_h_m_mines() const
{
	return m_c_mines;
}
bool Map::Get_lost_b() const
{
	return m_lost_b;
}
bool Map::Get_win_b() const
{
	return m_win_b;
}
void Map::Set_lost_b(bool && b)
{
	m_lost_b = b;
}
void Map::Set_win_b(bool && b)
{
	m_win_b = b;
}