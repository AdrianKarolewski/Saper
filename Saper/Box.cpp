#include "Box.h"

Box::Box() : box_view(new sf::RectangleShape({ 0,0 }))
{
	box_view->setFillColor(sf::Color(160, 160, 160));
	box_view->setOutlineThickness(2.f);
	box_view->setOutlineColor(sf::Color(0, 0, 255));
}
Box::Box(sf::Vector2f &&v) : box_view(new sf::RectangleShape(v))
{
	box_view->setFillColor(sf::Color(160, 160, 160));
	box_view->setOutlineThickness(2.f);
	box_view->setOutlineColor(sf::Color(0, 0, 255));
}
Box::Box(const Box& pat) : box_view(new sf::RectangleShape(pat.box_view->getSize()))
{
	this->is_block = pat.is_block;
	this->is_flagged = pat.is_flagged;
	this->is_mine = pat.is_mine;
	this->m_value = pat.m_value;
	this->show_it = pat.show_it;
}
Box::Box(Box&& pat)
{
	this->box_view = pat.box_view;

	pat.box_view = nullptr;

	this->is_block = pat.is_block;
	this->is_flagged = pat.is_flagged;
	this->is_mine = pat.is_mine;
	this->m_value = pat.m_value;
	this->show_it = pat.show_it;
}
Box::~Box()
{
	delete box_view;
}
void Box::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(*this->box_view, state);
}
const sf::Vector2f & Box::Get_box_pos() const
{
	return this->box_view->getPosition();
}
const sf::Vector2f & Box::Get_box_size() const
{
	return this->box_view->getSize();
}
const char& Box::Get_val() const
{
	return m_value;
}
const bool& Box::Get_is_block_b() const
{
	return is_block;
}
const bool& Box::Get_is_flagged_b() const
{
	return is_flagged;
}
const bool& Box::Get_is_show_it() const
{
	return show_it;
}
const bool& Box::Get_is_mine_b() const
{
	return is_mine;
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
void Box::Set_val(const char & b)
{
	m_value = b;
}
Box & Box::operator++(int)
{
	m_value++;
	return *this;
}
