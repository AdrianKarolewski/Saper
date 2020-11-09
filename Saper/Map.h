#pragma once

#include "Box.h"
#define BOX_S 0.015625
class Map
{
public:
	sf::Texture* texturs = nullptr;

	Map(unsigned int& m_w, unsigned int& m_h, unsigned int& c_mi, sf::RenderWindow& Saper);
	~Map();

	Map* Append_mines_add_val(Map* map1);
	Map* Update_val_box(Map* map1, const unsigned int& x, const unsigned int& y);
	Map* Draw_boxes(sf::RenderWindow& window_sap, Map* map1);

	void Flagged_box(const unsigned int& x, const unsigned int& y);
	void Un_flagged_box(const unsigned int& x, const unsigned int& y);
	void Add_to_show(const unsigned int& y, const unsigned int& x);
	void Show_boombs();
	bool Show_one_bomb();
	void Click_handle(const unsigned int& x, const unsigned int& y, sf::RenderWindow& Saper, sf::Event event);
	const unsigned int & Get_h_m_b_flagged() const;
	const unsigned int & Get_h_m_flagged() const;
	const unsigned int & Get_h_m_mines() const;
	const bool & Get_lost_b() const;
	const bool & Get_win_b() const;
	void Set_win_b(bool&& b);
	void Set_lost_b(bool&& b);
	bool Show_box(const unsigned int& x, const unsigned int& y);
	bool Click_on_map(const unsigned int& x, const unsigned int& y);
		
private:
	const bool & Is_win();
	unsigned int m_how_much_bombs_flagged{ 0 };
	unsigned int m_how_much_put_flags{ 0 };
	const unsigned int m_map_w{ 0 }, m_map_h{ 0 }, m_c_mines{ 0 };
	bool m_win_b{ 0 }, m_lost_b{ 0 };
	Box*** t_boxes{ nullptr };
};

