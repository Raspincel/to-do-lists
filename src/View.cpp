#include "View.h"

void View::setView()
{
	m_page = 0;
	m_numberOfItems = 0;

	m_collectNames.clear();
	m_collectNames.seekg(0);

	extractNames();
	setPositions();
}

void View::extractNames()
{
	std::string ss;
	m_numberOfPages = 0;

	if (m_viewingList == -1)
	{
		BaseListDisplay::extractNames();
		setFinishedLists();

	}
	else 
	{
		m_collectNames.open("Lists/" + m_lists[m_viewingList].getString() + ".txt");

		while (std::getline(m_collectNames, ss))
		{
			if (ss == "#")
			{
				m_numbersPosition = static_cast<int>(m_collectNames.tellg());
				break;
			}

			if (m_numberOfItems % 10 == 0)
				++m_numberOfPages;

			++m_numberOfItems;
		}

		m_items = new Option[m_numberOfItems];

		m_collectNames.clear();
		m_collectNames.seekg(0);

		for (int i{ 0 }; i < m_numberOfItems; ++i)
		{
			std::getline(m_collectNames, ss);
			m_items[i].setMessage(ss);
		}	

		m_collectNames.close();
		setCompletes();
	}
}

void View::setPositions()
{
	if (m_viewingList == -1)
	{
		BaseListDisplay::setPositions();
	}
	else
	{
		for (int i{ 0 }; i < m_numberOfItems; ++i)
			m_items[i].setPosition(screenSize::x, screenSize::y, 11, (i % 10) + 1);
	}
}

void View::setCompletes()
{
	std::string number;

	m_collectNames.open("Lists/" + m_lists[m_viewingList].getString() + ".txt");
	m_collectNames.clear();
	m_collectNames.seekg(m_numbersPosition);

	while (std::getline(m_collectNames, number))
	{
		m_items[std::atoi(number.c_str())].redOutline(m_lists[m_viewingList].getString(), -1);
		++m_itemsFinished;
	}

	m_collectNames.close();
}

void View::addNumberToList(int number)
{
	std::ofstream list{ "Lists/" + m_lists[m_viewingList].getString() + ".txt", std::ios::app };
	std::string ss;
	std::string snumber{ std::to_string(number) };

	list << std::to_string(number) << '\n';
}

void View::finishList()
{
	if (m_itemsFinished == m_numberOfItems)
	{
		std::ofstream ostr{ "Lists/listsNames.txt", std::ios::app};
		ostr << m_viewingList << '\n';
	}
}

void View::setFinishedLists()
{

	m_collectNames.clear();
	m_collectNames.open("Lists/listsNames.txt", std::ios::app);

	std::string bah;

	while (std::getline(m_collectNames, bah))
	{
		if (bah == "#")
			break;
	}
	
	while (std::getline(m_collectNames, bah))
	{
		m_lists[std::atoi(bah.c_str())].redOutline(m_lists[std::atoi(bah.c_str())].getString(), -1);
	}

	m_collectNames.close();
}

void View::unsetFinishedLists(int target)
{
	std::ifstream istr{ "Lists/listsNames.txt", std::ios::app };
	std::string bah;
	std::string copy{};
	while (std::getline(istr, bah))
	{
		copy += bah;
		copy += '\n';

		if (bah == "#")
			break;
	}

	while (std::getline(istr, bah))
	{
		if (bah == std::to_string(target))
			continue;

		copy += bah;
		copy += '\n';
	}

	istr.close();
	std::ofstream ostr{ "Lists/listsNames.txt" };

	ostr << copy;

}

void View::renderPage(sf::RenderWindow& window)
{

	BaseListDisplay::renderPage(window);

	m_arrow.draw(window);

	if (ChooseView::step == Viewing::item)
	{
		int j{ m_page * 10 };
		int k{ (m_numberOfItems - j < 10) ? m_numberOfItems : 10 + j };

		for (int i{ j }; i < k; ++i)
			m_items[i].renderText(window);
	}
}

void View::updateList()
{
	resetView();
	setView();
}

void View::mouseClicked(const sf::Vector2f& mousePos)
{
	BaseListDisplay::mouseClicked(mousePos);

	if (m_arrow.isHovering(mousePos))
	{
		m_arrow.arrowInteraction();
		resetView();
		updateList();
		return;
	} 
	else if (ChooseView::step == Viewing::lists)
	{

		int j{ m_page * 10 };
		int k{ (m_numberOfLists - j < 10) ? m_numberOfLists : 10 + j };

		for (int i{ j }; i < k; ++i)
		{
			if (m_lists[i].isHovering(mousePos))
			{
				m_viewingList = i;
				setView();
				ChooseView::step = Viewing::item;
				return;
			}
		}
	}
	else if (ChooseView::step == Viewing::item)
	{
		int j{ m_page * 10 };
		int k{ (m_numberOfItems - j < 10) ? m_numberOfItems : 10 + j };

		for (int i{ j }; i < k; ++i)
		{
			if (m_items[i].isHovering(mousePos))
			{
				if (m_items[i].redOutline(m_lists[m_viewingList].getString(), i))
				{
					--m_itemsFinished;
					unsetFinishedLists(m_viewingList);
					return;
				}

				++m_itemsFinished;
				addNumberToList(i);
				finishList();
				return;

			}
		}
	}
}

void View::resetView()
{
	delete[] m_lists;
	m_lists = nullptr;
	delete[] m_items;
	m_items = nullptr;

	m_viewingList = -1;
	m_numberOfPages = 0;
	m_page = 0;
	m_numberOfItems = 0;
	m_numberOfLists = 0;
	m_itemsFinished = 0;

}

void View::hovering(const sf::Vector2f& mousePos)
{

	BaseListDisplay::hovering(mousePos);


	bool mouseHovering{ m_arrow.isHovering(mousePos) };
	m_arrow.hovering(mouseHovering);
	if (mouseHovering)
		return;

	if (ChooseView::step == Viewing::item)
	{
		int j{ m_page * 10 };
		int k{ (m_numberOfItems - j < 10) ? m_numberOfItems : 10 + j };

		for (int i{ j }; i < k; ++i)
		{
			m_items[i].outline(mousePos);
			if (m_items[i].isHovering(mousePos))
			{
				return;
			}
		}
	}
}
