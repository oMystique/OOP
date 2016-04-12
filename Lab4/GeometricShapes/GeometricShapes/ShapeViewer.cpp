#include "stdafx.h"
#include "ShapeViewer.h"

void CShapeViewer::ProcessEvent()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

void CShapeViewer::Exec(std::vector<std::shared_ptr<IShapeView>> const & shapes)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	m_window.create(sf::VideoMode(580, 420), "Shape Viewer", sf::Style::Default, settings);

	while (m_window.isOpen())
	{

		ProcessEvent();

		m_window.clear(sf::Color::White);
		for (auto &it : shapes)
		{
			m_window.draw(*it);
		}
		m_window.display();
	}
}
