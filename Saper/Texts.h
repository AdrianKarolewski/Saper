#pragma once
#include <SFML/Graphics.hpp>


class Texts : public sf::Drawable
{
	sf::Text text_on_map;
	sf::RectangleShape box_for_text;
	friend class Game;
public:
	Texts(sf::Font &font,const char* st_come,sf::Color color,const int& size_s_come, sf::Vector2f vector_box_size, sf::Vector2f vector_box_position);
	~Texts();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	bool click_on_text_box(const unsigned int& x, const unsigned int &y);
};


