#include "Box.h"

Box::Box(sf::Vector2f &&v) : box_view(new sf::RectangleShape(v))
{
	box_view->setFillColor(sf::Color(160, 160, 160));
	box_view->setOutlineThickness(2.f);
	box_view->setOutlineColor(sf::Color(0, 0, 255));
}
Box::~Box()
{
	delete box_view;
}
void Box::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(*this->box_view, state);
}
sf::Vector2f Box::Get_box_pos()
{
	return this->box_view->getPosition();
}
sf::Vector2f Box::Get_box_size()
{
	return this->box_view->getSize();
}
const char& Box::Get_val()
{
	return m_value;
}
void Box::Clear_tex()
{
	box_view->setTexture(NULL);
}
void Box::Set_tex(sf::Texture &t)
{
	box_view->setTexture(&t);
}
void Box::Set_position(sf::Vector2f &v)
{
	box_view->setPosition(v);
}
void Box::Set_is_flagged(bool&& b)
{
	is_flagged = b;
}
void Box::Set_block(bool && b)
{
	is_block = b;
}
void Box::Set_show_it(bool&& b)
{
	show_it = b;
}
void Box::Set_mine(bool&& b)
{
	is_mine = b;
}
void Box::Set_val(const char b)
{
	m_value = b;
}
void Box::Up_value()
{
	m_value++;
}
bool Box::Is_block_b()
{
	return is_block;
}
bool Box::Is_flagged_b()
{
	return is_flagged;
}
bool Box::Is_show_it()
{
	return show_it;
}
bool Box::Is_mine_b()
{
	return is_mine;
}