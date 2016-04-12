#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "IShapeView.h"

class CShapeViewer
{
public:
	void Exec(std::vector<std::shared_ptr<IShapeView>> const &shapes);
private:
	void ProcessEvent();
private:
	sf::RenderWindow m_window;
};