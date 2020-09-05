#include "Box.h"
Box::Box(char val, bool is_m, bool is_b, bool is_fl, bool show_i)
{
	value = val;
	is_mine = is_m;
	is_block = is_b;
	is_flagged = is_fl;
	show_it = show_i;
	box_view.setSize(sf::Vector2f{ 30.f, 30.f });
	box_view.setFillColor(sf::Color(160, 160, 160));
	box_view.setOrigin(sf::Vector2f{ 10.f,10.f });
	box_view.setOutlineThickness(2.f);
	box_view.setOutlineColor(sf::Color(0, 0, 255));
}
Box::~Box()
{

}
void Box::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->box_view, state);
}
bool Box::is_block_b()
{
	return is_block;
}
bool Box::is_flagged_b()
{
	return is_flagged;
}
bool Box::is_show_it()
{
	return show_it;
}