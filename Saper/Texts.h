#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>

class Texts : public sf::Drawable
{
public:
	sf::Text text_on_map;
	sf::RectangleShape box_for_text;
public:
	Texts(sf::Font font,const char* st_come,sf::Color color,int size_s_come,sf::Vector2f vector_come_text, sf::Vector2f vector_come_box, sf::Vector2f vector_come_box_position);
	~Texts();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};


