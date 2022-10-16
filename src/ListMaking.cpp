#include "ListMaking.h"

void ListMaking::setPositions()
{
	int j{ m_page * 10 };

	for (int i{ 0 }; i < m_numberOfEntries; ++i)
		m_textEntries[i].setPosition(screenSize::x, screenSize::y, 11, (i % 10) + 1);
}

void ListMaking::updateText(const char message)
{
	if (m_message.size() < 42)
	{
		m_message += message;
		m_textEntries[m_entry].setMessage(m_message);
		if (m_textEntries[m_entry].size() < 42)
			m_textEntries[m_entry].setMessage('_');
	}
}

void ListMaking::deleteChar()
{
	if (m_message.size() > 0)
	{
		m_message.pop_back();
		m_textEntries[m_entry].setMessage(m_message);
		m_textEntries[m_entry].setMessage('_');
	}
}

void ListMaking::next()
{
	if (m_message.size() == 0)
		m_message = " ";

	if (m_entry != 9 + (m_page * 10) && m_entry + 1 < m_numberOfEntries)
	{
		m_textEntries[m_entry].setMessage(m_message);
		++m_entry;
		if (m_message.size() == 0)
			m_message = "";
		else
			m_message = m_textEntries[m_entry].getString();
		m_textEntries[m_entry].setMessage('_');
	}
	else if (m_page + 1 < m_numberOfPages)
	{
		m_textEntries[m_entry].setMessage(m_message);
		m_message = "";
		++m_page;
		++m_entry;
		m_textEntries[m_entry].setMessage('_');
	}
	else
	{
		m_textEntries[m_entry].setMessage(m_message);
		writeInFile();
	}
}

void ListMaking::resetText()
{
	delete[] m_textEntries;
	CreationStep::state = Render::naming;
}

void ListMaking::writeInFile()
{
	std::ifstream originalFile{ "Lists/listsNames.txt" };
	std::ofstream newFile{ "Lists/temp.txt" };
	
	newFile << m_listName << '\n';
	newFile << originalFile.rdbuf();

	newFile.close();
	originalFile.close();

	std::remove("Lists/listsNames.txt");
	std::rename("Lists/temp.txt", "Lists/listsNames.txt");

	std::ofstream newList{ "Lists/" + m_listName + ".txt" , std::ios::app};

	std::string str{};

	for (int i{ 0 }; i < m_numberOfEntries; ++i)
	{
		str = m_textEntries[i].getString();
		if (str.empty() || str == " ")
			continue;

		newList << str << '\n';
	}

	newList << "#" << '\n';

	newList.close();
	resetText();
	ScreenState::screen = Screen::menu;


}

void ListMaking::createList(int numberOfEntries)
{
	m_numberOfEntries = numberOfEntries;

	if (m_numberOfEntries)
	{
		m_numberOfPages = static_cast<int>(m_numberOfEntries / 10);
		if (m_numberOfEntries % 10 != 0)
			++m_numberOfPages;

		m_textEntries = new Option[m_numberOfEntries];
		m_entry = 0;
		m_page = 0;
		m_message = "";
		m_textEntries[m_entry].setMessage("_");
		setPositions();

		for (int i{ 0 }; i < m_numberOfEntries; ++i)
			m_textEntries[i].setNumber(i + 1);
	}
}

void ListMaking::setName(std::string name)
{
	m_listName = name;
}

void ListMaking::renderPage(sf::RenderWindow& window)
{
	// m_numberOfPages = ceil(static_cast<int>(static_castm_numberOfEntries / 10));

	if (m_page > 0)
		m_leftArrow.draw(window);
	if (m_page + 1 < m_numberOfPages)
		m_rightArrow.draw(window);

	int j{ m_page * 10 };
	int k{ (m_numberOfEntries - j < 10) ? m_numberOfEntries : 10 + j };

	for (int i{ j }; i < k; ++i)
	{
		m_textEntries[i].renderText(window);

	}
}

bool ListMaking::writeText(const sf::Vector2f& mousePos)
{
	bool pause{ true };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		next();
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
	{
		deleteChar();
		pause = false;
	}
	
	if (pause)
		pause = writeNumbers();

	if (pause)
		pause = writeLetters();

	return pause;
}

void ListMaking::hovering(const sf::Vector2f& mousePos)
{
	bool hovering{ m_leftArrow.isHovering(mousePos) };
	m_leftArrow.hovering(hovering);

	if (hovering)
		return;

	hovering = m_leftArrow.isHovering(mousePos);

	m_rightArrow.hovering(hovering);

	if (hovering)
		return;

	int j{ m_page * 10 };
	int k{ (m_numberOfEntries - j < 10) ? m_numberOfEntries : 10 + j };

	for (int i{ j }; i < k; ++i)
	{
		m_textEntries[i].outline(mousePos);

	}
}

void ListMaking::wasTabPressed()
{
	m_textEntries[m_entry].setMessage(m_message);

	if ((m_entry + 1) % 10 == 0)
		m_entry -= 9;
	else if (m_entry + 1 < m_numberOfEntries)
		++m_entry;
		
	else if (m_numberOfEntries - m_entry < 10)
		while (m_entry % 10 != 0)
		--m_entry;

	m_message = m_textEntries[m_entry].getString();
	m_textEntries[m_entry].setMessage('_');
}

void ListMaking::mouseClicked(const sf::Vector2f& mousePos)
{
	if (m_leftArrow.isHovering(mousePos) && m_page > 0)
	{
		m_leftArrow.arrowInteraction();
		--m_page;
		return;
	}
	else if (m_rightArrow.isHovering(mousePos) && m_numberOfPages > m_page + 1)
	{
		++m_page;
		m_rightArrow.arrowInteraction();
		return;
	}

	int j{ m_page * 10 };
	int k{ (m_numberOfEntries - j < 10) ? m_numberOfEntries : 10 + j };

	for (int i{ j }; i < k; ++i)
	{
		if (m_textEntries[i].isHovering(mousePos))
		{
			m_textEntries[m_entry].setMessage(m_message);
			m_entry = i;
			m_message = m_textEntries[i].getString();
			m_textEntries[i].setMessage('_');
			return;
		}
	}
}
