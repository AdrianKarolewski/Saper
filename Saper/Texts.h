#pragma once
#include <SFML/Graphics.hpp>


class Texts : public sf::Drawable
{
public:
	Texts(sf::Font& font, const char* st_come, const int& size_s_come, sf::Vector2f vector_box_size, sf::Vector2f vector_box_position);
	~Texts();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	void Set_text(std::string && s);
	void Center_text();
	void Focus_on_text_box(const unsigned int& x, const unsigned int& y);
	bool Click_on_text_box(const unsigned int& x, const unsigned int& y) const;

private:
	sf::Text *text_on_map = nullptr;
	sf::RectangleShape *box_for_text = nullptr;
};


