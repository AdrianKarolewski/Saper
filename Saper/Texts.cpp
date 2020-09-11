#include "Texts.h"
#include <SFML/Graphics.hpp>
#include <string.h>

Texts::Texts(sf::Font &font, const char* st_come, sf::Color color, int size_s_come, sf::Vector2f vector_come_text, sf::Vector2f vector_come_box, sf::Vector2f vector_come_box_position)
{
	text_on_map.setFont(font);
	text_on_map.setString(st_come);
	text_on_map.setFillColor(color);
	text_on_map.setCharacterSize(size_s_come);
	text_on_map.setPosition(vector_come_text);
	box_for_text.setFillColor(sf::Color(160, 160, 160));
	box_for_text.setSize(vector_come_box);
	box_for_text.setOrigin({ vector_come_box.x / 2, vector_come_box.y / 2 });
	box_for_text.setPosition(vector_come_box_position);
	
}
Texts::~Texts()
{

}
void Texts::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	
	target.draw(this->box_for_text, state);
	target.draw(this->text_on_map, state);
}