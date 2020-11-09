#include "Texts.h"
#define BOX_FILL_COLOR {160,160,160}
#define BOX_OUTLINE_COLOR {0,0,255}
#define FONT_COLOR { 0, 0, 255 }
#define BOX_FILL_COLOR_FOCUS {10,10,10}

Texts::Texts(sf::Font &font, const char* st_come,const int &size_s_c, 
	sf::Vector2f && vector_box_size, sf::Vector2f && vector_box_position)
	:text_on_map(new sf::Text(st_come,font,size_s_c)), 
	box_for_text(new sf::RectangleShape(vector_box_size))
{
	Center_text();
	box_for_text->setFillColor(BOX_FILL_COLOR);
	box_for_text->setOrigin({ vector_box_size.x / 2, vector_box_size.y / 2 });
	box_for_text->setPosition(vector_box_position);
	box_for_text->setOutlineThickness(2.f);
	box_for_text->setOutlineColor(BOX_OUTLINE_COLOR);

	text_on_map->setFillColor(FONT_COLOR);
	text_on_map->setOrigin(text_on_map->getGlobalBounds().width / 2,
		text_on_map->getGlobalBounds().height / 2 + size_s_c / 4);
	text_on_map->setPosition(vector_box_position);
}
Texts::Texts(const Texts& pat) :
text_on_map(new sf::Text(pat.text_on_map->getString(), *(pat.text_on_map->getFont()), pat.text_on_map->getCharacterSize())),
box_for_text(new sf::RectangleShape(box_for_text->getSize()))
{
	this->box_for_text->setFillColor(pat.box_for_text->getFillColor());
	this->box_for_text->setOrigin(pat.box_for_text->getOrigin());
	this->box_for_text->setPosition(pat.box_for_text->getPosition());
	this->box_for_text->setOutlineThickness(pat.box_for_text->getOutlineThickness());
	this->box_for_text->setOutlineColor(pat.box_for_text->getOutlineColor());

	this->text_on_map->setFillColor(pat.text_on_map->getFillColor());
	this->text_on_map->setOrigin(pat.text_on_map->getOrigin());
	this->text_on_map->setPosition(pat.text_on_map->getPosition());	
}
Texts::Texts(Texts&& pat)
{
	this->text_on_map = pat.text_on_map;
	this->box_for_text = pat.box_for_text;
	pat.text_on_map = nullptr;
	pat.box_for_text = nullptr;
}
Texts::~Texts()
{
	delete text_on_map, box_for_text;
}
void Texts::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(*this->box_for_text, state);
	target.draw(*this->text_on_map, state);
}
bool Texts::Click_on_text_box(const unsigned int &x, const unsigned int& y) const
{
	if (((box_for_text->getPosition().x - box_for_text->getSize().x / 2) < x) 
		&& ((box_for_text->getPosition().x + box_for_text->getSize().x / 2) > x))
	{
		if (((box_for_text->getPosition().y - box_for_text->getSize().y / 2) < y) 
			&& ((box_for_text->getPosition().y + box_for_text->getSize().y / 2) > y))
		{
			return 1;
		}
	}
	return 0;
}
void Texts::Set_text(std::string && s)
{
	text_on_map->setString(s);
}
void Texts::Center_text()
{
	text_on_map->setOrigin(text_on_map->getGlobalBounds().width / 2, 
		text_on_map->getGlobalBounds().height / 2 + text_on_map->getCharacterSize() / 4);
	text_on_map->setPosition(box_for_text->getPosition());
}