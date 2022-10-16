#include "Creation.h"


void Creation::setTexts()
{
	m_introTextName.setMessage("What will be the name or your to-do list?");
	m_introTextSize.setMessage("How many items will your to-do list have?");
}

void Creation::setPositions()
{
	m_introTextName.setPosition(screenSize::x, screenSize::y, 5, 1);
	m_listName.setPosition(screenSize::x, screenSize::y, 5, 2);

	m_introTextSize.setPosition(screenSize::x, screenSize::y, 5, 3);
	m_listSize.setPosition(screenSize::x, screenSize::y, 5, 4);
}


void Creation::deleteChar()
{
	if (m_message.size() > 0)
	{
		m_message.pop_back();
		if (CreationStep::state == Render::naming)
		{
			m_listName.setMessage(m_message);
			if (m_listName.size() < 42)
				m_listName.setMessage('_');
		}
		else
		{
			m_listSize.setMessage(m_message);
			while (m_listSize.size() < 2)
				m_listSize.setMessage('_');
		}
	}
}

void Creation::updateText(const char message)
{
	// enforces the 0–42 and 0–999 limit
	if (CreationStep::state == Render::naming && m_message.size() < 42)
	{
		m_message.append(std::string{ message });
		m_listName.setMessage(m_message);
		if (m_listName.size() < 42)
			m_listName.setMessage('_');
	}
	else if (CreationStep::state == Render::sizing && m_message.size() < 2)
	{
		m_message.append(std::string{ message });
		if (m_listSize.getString()[0] != '_')
		{
			if (stoi(m_message) > 50)
				m_message = "50";
		}
		m_listSize.setMessage(m_message);
		while (m_listSize.size() < 2)
			m_listSize.setMessage('_');
	}

	// fills the digits with underlines, like: ___, instead of only a vacuum

}

void Creation::render(sf::RenderWindow& window)
{
	// if false = is in the first step
	// if true = is in the second step
	if (CreationStep::state == Render::writing)
		m_lists.renderPage(window);
	else
	{
		m_introTextName.renderText(window);
		m_introTextSize.renderText(window);
		m_listName.renderText(window);
		m_listSize.renderText(window);
	}

	// the arrow must be drawn in every page besides the main menu
	m_arrow.draw(window);
}

void Creation::resetText()
{
	m_listName.setMessage("_");
	m_listSize.setMessage("__");
	m_message = "";
	if (CreationStep::state == Render::writing)
		m_lists.resetText();
}


bool Creation::writeText(const sf::Vector2f& mousePos)
{
	bool pause{ true };

	if (CreationStep::state == Render::writing)
	{
		pause = m_lists.writeText(mousePos);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
			m_lists.wasTabPressed();
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			deleteChar();
			pause = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			next();
			pause = false;
		}
		
		if (pause)
			pause = writeNumbers();

		if (pause && CreationStep::state == Render::naming)
			pause = writeLetters();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
			wasTabPressed();
			pause = false;
		}
	}


	return pause;
}

void Creation::next()
{
	if (CreationStep::state == Render::naming && m_message != "")
	{
		CreationStep::state = Render::sizing;
		m_listName.setMessage(m_message); // to remove the final underline
		m_lists.setName(m_message);
		if (m_listSize.getString()[0] == '_')
			m_message = "";
		else
			m_message = m_listSize.getString();

		while (m_listSize.size() < 2)
			m_listSize.setMessage('_');
	}
	else if (CreationStep::state == Render::sizing && m_message.size() && isSizeValid())
	{
			m_lists.createList(stoi(m_message));
			resetText();
			CreationStep::state = Render::writing;
	}
}

void Creation::wasTabPressed()
{
	if (CreationStep::state == Render::naming && m_message != "")
	{
		next();

		m_message = (m_listSize.getString());
		std::erase(m_message, '_');
		m_listSize.setMessage(m_message);

		while (m_listSize.size() < 2)
			m_listSize.setMessage('_');
	}
	else if (CreationStep::state == Render::sizing)
	{
		CreationStep::state = Render::naming;
		m_listSize.setMessage(m_message); // to remove the final underline

		m_message = m_listName.getString();
		std::erase(m_message, '_');
		m_listName.setMessage(m_message);

		if (m_listName.size() < 42)
			m_listName.setMessage('_');
	}
	else if (CreationStep::state == Render::writing)
		m_lists.wasTabPressed();
}

void Creation::mouseClicked(const sf::Vector2f& mousePos)
{
	if (m_arrow.isHovering(mousePos))
	{
		m_arrow.arrowInteraction();
		resetText();

	}

	if (CreationStep::state != Render::writing)
	{
		if ((m_listName.isHovering(mousePos) && CreationStep::state != Render::naming) || 
			(m_listSize.isHovering(mousePos)) && CreationStep::state != Render::sizing)
		{
			wasTabPressed();
			return;
		}
	}
	else
		m_lists.mouseClicked(mousePos);
}

void Creation::hovering(const sf::Vector2f& mousePos)
{
	bool mouseHovering{ m_arrow.isHovering(mousePos) };
	m_arrow.hovering(mouseHovering);
	if (mouseHovering)
		return;

	if (CreationStep::state != Render::writing)
	{
		m_listName.outline(mousePos);
		m_listSize.outline(mousePos);
	}
	else
	{
		m_lists.hovering(mousePos);
	}
}

bool Creation::isSizeValid()
{
	if (m_listSize.getString()[0] != '_')
		return stoi(m_listSize.getString()) > 0;

	return false;
}
