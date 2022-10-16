#pragma once
#ifndef LISTMAKING_H
#define LISTMAKING_H

#include <SFML/Graphics.hpp>

#include <cmath>
#include <fstream>
#include <string>
#include <vector>

// Classes and etc
#include "LateralArrow.h"
#include "BaseText.h"
#include "Option.h"


// Constants and functions
#include "constants.h"

// There are two definitions for a "page" in the creation screen. The relevant 
// defition to this .h file is: a "page" is set of up to 10 list items in which
// the user can write whatever they want. When one of the lateral arrows is
// clicked (or enter, when writing at the tenth item of the page), the current
// page is changed, if there is any more pages to see.

// More informations about the second definition inside the ListMaking.h file

class ListMaking : public BaseText
{
private:
	Option* m_textEntries;	// array of boxes for the user to write in
	int m_entry;			// current box where the user is writing in
	int m_numberOfEntries;	// total amount of boxes for the user to write in
	int m_page;				// current page the user is visualizing
	int m_numberOfPages;	// total amount of pages
	std::string m_message;	// whatever the user writes in each box is stored here
	std::string m_listName;	// the list's name for later creating a .txt with this name

	LateralArrow m_leftArrow;
	LateralArrow m_rightArrow;

	// initial setup
	void setPositions();

	void updateText(const char message) override;
	void deleteChar() override;

	// changes the box where the user is writing in, or the page
	void next() override;

	// saves everything that was written in a .txt file
	void writeInFile();

public:
	ListMaking() : m_textEntries{ nullptr }, m_leftArrow{ Direction::left }, m_rightArrow{ Direction::right }
	{

	}

	// inital setup
	void createList(int numberOfEntries);
	void setName(std::string name);

	void resetText() override;

	// renders everything
	void renderPage(sf::RenderWindow& window);

	bool writeText(const sf::Vector2f& mousePos) override;
	void hovering(const sf::Vector2f& mousePos);
	void wasTabPressed();
	void mouseClicked(const sf::Vector2f& mousePos);
};


#endif // !LISTMAKING_H
