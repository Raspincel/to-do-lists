#pragma once
#ifndef BASETEXT_H
#define BASETEXT_H

#include <SFML/Graphics.hpp>

// This class is inherited by the class Creation and ListMaking (both part of the creation page, since that's the only place typing things is necessary). Originally, it was meant to be called from some random function, which would acess either the Creation or ListMaking classes depending on the context. As it is now, this does not happen anymore, but when the change was made the classes were already created, so I mantained it this way. After all, all is working normal, so there is no need to change the code

class BaseText
{
protected:
	virtual void updateText(const char message) = 0; // updates according to the new set message
	virtual void deleteChar() = 0; // deletes last char
	virtual void next() = 0; // goes to the next page/text "box"

	virtual void resetText() = 0; // resets all texts and classes involved when leaving the creation screen
	virtual bool writeText(const sf::Vector2f& mousePos) = 0; // adds new characters to the text "boxes"

	// used to type characters from a–z
	virtual bool writeNumbers(); 
	// used to type numbers from 0–9
	virtual bool writeLetters();
};


#endif // !BASETEXT_H
