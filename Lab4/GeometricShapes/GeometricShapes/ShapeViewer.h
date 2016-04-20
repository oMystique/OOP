#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "IShapeView.h"

typedef std::vector<std::shared_ptr<IShapeView>> ViewShapesPtrs;

class CShapeViewer
{
public:
	void Exec(ViewShapesPtrs const &shapes);
private:
	void ProcessEvent();
private:
	sf::RenderWindow m_window;
};