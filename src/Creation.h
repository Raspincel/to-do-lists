#pragma once

#ifndef CREATION_H
#define CREATION_H

#include <array>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

// Classes and etc
#include "Arrow.h"
#include "BaseText.h"
#include "ListMaking.h"
#include "Option.h"

// Constants and functions
#include "constants.h"

// There are two definitions for a "page" in the creation screen. The relevant 
// defition to this .h file is: a "page" is more like "a step in the process of
// creating a list". There are two steps: setting the name of the list and the 
// number of items that the list will have, and filling each item with the desi-
// red content. The current page/step is defined with only one boolean variable:
// "m_naming". It is set to "true" to indicate the first step, and "false" to 
// indicate the second

// More informations about the second definition inside the ListMaking.h file

class Creation : public BaseText
{
private:
	Option m_introTextName;		// text asking to tell the name of the list
	Option m_introTextSize;		// test asking to tell the size of the list
	Option m_listName;			// user's answer, a name with up to 42 characters
	Option m_listSize;			// user's answer, from 0 to 999. It's not possible to create a list of size 0
	std::string m_message;		// storing (temporary) the answers to facilitate the texts manipulation
	
	Arrow m_arrow;
	ListMaking m_lists;			// given the answers, the list creation occurs here
	
	// initial setup
	void setTexts();
	void setPositions();

	// deletes the last char and places an underline in the end
	void deleteChar() override;

	// update and rendering functions
	void updateText(const char message) override;

	// Called when leaving the page
	void resetText();

public:
	Creation() :
			m_message{ "" },
			m_listName{ "_" },
			m_listSize{ "" }
	{
		setTexts();
		setPositions();
	}

	// called inside main() to render everything
	void render(sf::RenderWindow& window);



	// reacts to interactions with the keyboard
	bool writeText(const sf::Vector2f& mousePos) override;

	// change to the next page or text box when ENTER is pressed
	void next();

	void wasTabPressed();
	void mouseClicked(const sf::Vector2f& mousePos);

	void hovering(const sf::Vector2f& mousePos);
	bool isSizeValid();
};


#endif // !CREATION_H
