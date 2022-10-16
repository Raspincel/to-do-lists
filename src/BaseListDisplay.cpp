#include "BaseListDisplay.h"

void BaseListDisplay::extractNames()
{
	std::string tempStr;
	m_collectNames.clear();

	m_collectNames.open("Lists/listsNames.txt", std::ios::app);

	m_numberOfPages = -1;

	while (std::getline(m_collectNames, tempStr))
	{
		if (m_numberOfLists % 10 == 0)
			++m_numberOfPages;

		if (tempStr == "#")
			break;

		++m_numberOfLists;
	}

	m_lists = new Option[m_numberOfLists];

	m_collectNames.clear();
	m_collectNames.seekg(0);

	for (int i{ 0 }; i < m_numberOfLists; ++i)
	{
		std::getline(m_collectNames, tempStr);
		m_lists[i].setMessage(tempStr);
	}

	m_collectNames.close();
}

void BaseListDisplay::setPositions()
{
	for (int i{ 0 }; i < m_numberOfLists; ++i)
		m_lists[i].setPosition(screenSize::x, screenSize::y, 11, (i % 10) + 1);
}

void BaseListDisplay::renderPage(sf::RenderWindow& window)
{
	// arrow.draw(window);

	if (m_page > 0)
		m_leftArrow.draw(window);
	if (m_page + 1 < m_numberOfPages)
		m_rightArrow.draw(window);

	if (ChooseView::step != Viewing::item)
	{
		int j{ m_page * 10 };
		int k{ (m_numberOfLists - j < 10) ? m_numberOfLists : 10 + j };

		for (int i{ j }; i < k; ++i)
			m_lists[i].renderText(window);
	}
}

void BaseListDisplay::mouseClicked(const sf::Vector2f& mousePos)
{
	if (m_leftArrow.isHovering(mousePos) && m_page > 0)
	{
		m_leftArrow.arrowInteraction();
		--m_page;
	}

	else if (m_rightArrow.isHovering(mousePos) && m_numberOfPages > m_page + 1)
	{
		++m_page;
		m_rightArrow.arrowInteraction();
	}
}

void BaseListDisplay::hovering(const sf::Vector2f& mousePos)
{
	bool hovering{ m_leftArrow.isHovering(mousePos) };
	m_leftArrow.hovering(hovering);

	if (hovering)
		return;

	hovering = m_leftArrow.isHovering(mousePos);

	m_rightArrow.hovering(hovering);
	
	if (hovering) 
		return;


	if (ChooseView::step != Viewing::item)
	{
		int j{ m_page * 10 };
		int k{ (m_numberOfLists - j < 10) ? m_numberOfLists : 10 + j };

		for (int i{ j }; i < k; ++i)
		{
			m_lists[i].outline(mousePos);
		}
	}
}
