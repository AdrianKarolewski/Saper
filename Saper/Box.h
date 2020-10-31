#pragma once
#include <SFML/Graphics.hpp>

class Box : public sf::Drawable
{
public:
	Box(sf::Vector2f && v);
	~Box();
	sf::Vector2f Get_box_size();
	sf::Vector2f Get_box_pos();
	void Set_tex(sf::Texture &t);
	void Clear_tex();
	void Set_position(sf::Vector2f &v);
	void Set_block(bool&& b);
	void Set_show_it(bool&& b);
	void Set_mine(bool&& b);
	void Set_is_flagged(bool&& b);
	void Set_val(const char b);
	void Up_value();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;

	const char& Get_val();
	bool Is_mine_b();
	bool Is_block_b();
	bool Is_flagged_b();
	bool Is_show_it();
private:
	char m_value = '0';
	bool is_mine = 0, is_block = 0, is_flagged = 0, show_it = 0;
	sf::RectangleShape *box_view = nullptr;
};

