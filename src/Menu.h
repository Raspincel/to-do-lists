#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#include <array>
#include <string_view>

// Classes and etc
#include "Option.h"
#include "Screen.h"

// Variables and functions
#include "constants.h"

class Menu
{
private:
	Option m_creation;	// "create a list" option
	Option m_view;		// "view lists" option
	Option m_delete;	// "delete lists" option

	void updateMenuTexts(const sf::Vector2f& mousePos);
	void renderMenuTexts(sf::RenderWindow& window);

	void setTexts();
	void setPositions();
	void openCreationScreen();
	void openViewScreen();
	void openDeleteScreen();

public:
	Menu()
	{
		setTexts();
		setPositions();
	}

	// changes screens
	void ifClicked(const sf::Vector2f& mousePos);

	// renders the menu
	void render(const sf::Vector2f& mousePos, sf::RenderWindow& window);

	void hovering(const sf::Vector2f& mousePos);
};



#endif // !MENU_H