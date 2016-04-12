#pragma once
#include "IShapeView.h"
#include "Shape.h"


class CCircleView : public IShapeView
{
public:
	CCircleView(Vector2f const &pos, float radius
		, Color const &lineColor, Color const &fillColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
private:
	sf::CircleShape m_circle;
};