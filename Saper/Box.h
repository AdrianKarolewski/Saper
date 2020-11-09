#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Box : public sf::Drawable
{
public:
	Box();
	Box(sf::Vector2f && v);
	Box(const Box& pat);
	Box(Box&& pat);
	~Box();
	const sf::Vector2f & Get_box_size() const;
	const sf::Vector2f & Get_box_pos() const;
	const char& Get_val() const;
	const bool& Get_is_mine_b() const;
	const bool& Get_is_block_b() const;
	const bool& Get_is_flagged_b() const;
	const bool& Get_is_show_it() const;

	void Set_tex(sf::Texture &t);
	void Set_position(sf::Vector2f &v);
	void Set_block(bool&& b);
	void Set_show_it(bool&& b);
	void Set_mine(bool&& b);
	void Set_is_flagged(bool&& b);
	void Set_val(const char & b);
	
	void Clear_tex();
	Box & operator++(int);
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;

	
private:
	char m_value = '0';
	bool is_mine = 0, is_block = 0, is_flagged = 0, show_it = 0;
	sf::RectangleShape *box_view = nullptr;
};

