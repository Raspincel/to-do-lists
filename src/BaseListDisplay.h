#pragma once
#ifndef BASELISTDISPLAY_H

#include "Arrow.h"
#include "LateralArrow.h"
#include "Option.h"
#include <string>
#include <fstream>
#include "constants.h"

class BaseListDisplay
{
protected:
	Option* m_lists;
	LateralArrow m_leftArrow;
	LateralArrow m_rightArrow;

	std::ifstream m_collectNames;

	int m_numberOfLists;
	int m_page;
	int m_numberOfPages;

	virtual void extractNames();
	virtual void setPositions();


	BaseListDisplay() : m_numberOfLists{ 0 }, m_leftArrow{ Direction::left }, m_rightArrow{ Direction::right }
	{
	}

public:

	virtual void renderPage(sf::RenderWindow& window);
	virtual void mouseClicked(const sf::Vector2f& mousePos);
	virtual void hovering(const sf::Vector2f& mousePos);
};


#endif // !BASELISTDISPLAY_H


