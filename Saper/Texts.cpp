#include "Texts.h"

Texts::Texts(sf::Font &font, const char* st_come, sf::Color col,const int &size_s_c, sf::Vector2f vector_box_size, sf::Vector2f vector_box_position)
{
	text_on_map.setFont(font); text_on_map.setString(st_come); 	text_on_map.setFillColor(col);
	text_on_map.setCharacterSize(size_s_c);

	text_on_map.setOrigin(text_on_map.getGlobalBounds().width / 2,text_on_map.getGlobalBounds().height / 2 + size_s_c / 4);

	text_on_map.setPosition(vector_box_position);
	
	box_for_text.setFillColor(sf::Color(160, 160, 160));
	box_for_text.setSize(vector_box_size);
	box_for_text.setOrigin({ vector_box_size.x / 2, vector_box_size.y / 2 });
	box_for_text.setPosition(vector_box_position);
	box_for_text.setOutlineThickness(2.f);
	box_for_text.setOutlineColor(sf::Color(0, 0, 255));
}
Texts::~Texts()
{

}
void Texts::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	
	target.draw(this->box_for_text, state);
	target.draw(this->text_on_map, state);
}
bool Texts::click_on_text_box(const unsigned int &x, const unsigned int& y)
{
	if (((box_for_text.getPosition().x - box_for_text.getSize().x / 2) < x) 
		&& ((box_for_text.getPosition().x + box_for_text.getSize().x / 2) > x))
	{
		if (((box_for_text.getPosition().y - box_for_text.getSize().y / 2) < y) 
			&& ((box_for_text.getPosition().y + box_for_text.getSize().y / 2) > y))
		{
			return 1;
		}
	}
	return 0;
}