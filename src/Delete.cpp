#include "Delete.h"

void Delete::extractNames()
{
	BaseListDisplay::extractNames();
}

void Delete::setPositions()
{
	BaseListDisplay::setPositions();
	m_confirmationText.setPosition(screenSize::x, screenSize::y, 4, 1);
	m_yes.setPosition(screenSize::x, screenSize::y, 4, 2);
	m_no.setPosition(screenSize::x, screenSize::y, 4, 3);
}

void Delete::setTexts()
{
	std::string listName{ m_lists[m_toDeletion].getString() };

	m_confirmationText.setMessage("Do you want to delete '" + listName + "'?");
	m_yes.setMessage("Yes, delete '" + listName + "'");
	m_no.setMessage("No, don't delete '" + listName + "'");
}

void Delete::deleteList()
{
	std::ifstream ifstr{ "Lists/listsNames.txt", std::ios::app };
	std::string tempStr;

	std::string copy{};
	std::string toDelete{ m_lists[m_toDeletion].getString() };
	while (std::getline(ifstr, tempStr))
	{
		if (tempStr == toDelete)
			continue;

		copy += tempStr;
		copy += '\n';

		if (tempStr == "#")
			break;
	}

	std::string itemToDelete{ std::to_string(m_toDeletion) };
	while (std::getline(ifstr, tempStr))
	{
		if (tempStr == itemToDelete)
			continue;
		
		copy += tempStr;
		copy += '\n';
	}

	ifstr.close();

	std::string listName{ "Lists/" + toDelete + ".txt" };


	std::ofstream ofstr{ "Lists/listsNames.txt", std::ios::out | std::ios::trunc };
	ofstr << copy;

	ofstr.close();

	std::remove(listName.c_str());

	updateDeleting();
}

void Delete::renderDeletion(sf::RenderWindow& window)
{
	m_confirmationText.renderText(window);
	m_yes.renderText(window);
	m_no.renderText(window);
}

void Delete::renderPage(sf::RenderWindow& window)
{
	if (m_toDeletion == -1)
	{
		BaseListDisplay::renderPage(window);
		m_arrow.draw(window);
	}
	else
		renderDeletion(window);
}

void Delete::mouseClicked(const sf::Vector2f& mousePos)
{

	BaseListDisplay::mouseClicked(mousePos);

	if (m_toDeletion == -1)
	{
		if (m_arrow.isHovering(mousePos))
		{
			m_arrow.arrowInteraction();
			resetDelete();
			return;
		}
		
		int j{ m_page * 10 };
		int k{ (m_numberOfLists - j < 10) ? m_numberOfLists : 10 + j };


		for (int i{ j }; i < k; ++i)
		{
			if (m_lists[i].isHovering(mousePos))
			{
				m_toDeletion = i;
				setTexts();
			}
		}
	}
	else if (m_yes.isHovering(mousePos))
		deleteList();
	else if (m_no.isHovering(mousePos))
		m_toDeletion = -1;
}

void Delete::hovering(const sf::Vector2f& mousePos)
{
	if (m_toDeletion == -1) // change this -1
	{
		BaseListDisplay::hovering(mousePos);

		bool mouseHovering{ m_arrow.isHovering(mousePos) };
		m_arrow.hovering(mouseHovering);
		if (mouseHovering)
			return;
	}

	m_yes.outline(mousePos);
	m_no.outline(mousePos);
}

void Delete::updateDeleting()
{
	resetDelete();
	extractNames();
	setPositions();
	m_toDeletion = -1;
}

void Delete::resetDelete()
{
	delete[] m_lists;
	m_lists = nullptr;

	m_page = 0;
	m_numberOfPages = 0;
	m_numberOfLists = 0;


	m_collectNames.clear();
	m_collectNames.seekg(0);
	
}
