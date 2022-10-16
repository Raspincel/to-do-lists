#pragma once
#ifndef OPTION_H
#define OPTION_H

#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

#include "constants.h"

class Option
{
private:
	sf::Font m_font;	// m_text's font
	sf::Text m_text;	// the text of each box
	sf::Text m_number;

	Texture m_texture;

	std::string m_fileName;

	// initial setup
	void setFont();
	void setText();


	void setOutline();
	void removeOutline();

public:
	Option() : m_texture{ Texture::standard }
	{
		setText();
		setFont();
	}

	Option(const std::string_view message) : m_texture { Texture::standard }
	{
		m_number.setString("-1");
		setText();
		setFont();
		setMessage(message);
	}

	// adds outline colors if the mouse is hovering over the text box
	void outline(const sf::Vector2f& mousePos);
	bool redOutline(std::string fileName, int number);

	void setMessage(std::string_view message);
	void setMessage(const char message);
	void setNumber(int number);

	void setPosition(int sizeX, int sizeY, int proportion, int position);

	void renderText(sf::RenderWindow& window);

	bool isHovering(const sf::Vector2f& mousePos);

	int size(); // returns the string's length
	std::string getString();

};

#endif
