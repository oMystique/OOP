#include "stdafx.h"
#include "IShapeView.h"
#include "Shape.h"

sf::Color GetSFColor(Color const &color)
{
	return sf::Color(sf::Uint8(color.r), sf::Uint8(color.g), sf::Uint8(color.b));
}
