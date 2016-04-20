#pragma once
#include <SFML/Graphics.hpp>

struct Color;
sf::Color GetSFColor(Color const &color);

class IShapeView : public sf::Drawable
{
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};