#pragma once
#ifndef BASEARROW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string_view>

// Classes and etc
#include "constants.h"

class BaseArrow
{
protected:
	// to draw the arrow
	sf::VertexArray m_arrow;
	sf::Texture m_texture;

	// to confirm the current texture
	Texture m_currentTexture;

	// initial setup
	virtual void setArrow() = 0;
	virtual void setStandardTexture() = 0;
	virtual void setTextCoords() = 0;

	// when hovering over the arrow
	virtual void setHoverTexture() = 0;

public:
	BaseArrow() : m_arrow{ sf::TriangleFan, 8 }, m_currentTexture{ Texture::standard }
	{
	}

	// sees if the mouse is hovering over the arrow. If yes, changes the arrow's texture
	virtual void hovering(bool mouseHovering);

	// if the arrow is clicked, changes the screen
	virtual void arrowInteraction() = 0;

	// tells if the arrow was clicked
	virtual bool isHovering(const sf::Vector2f& mousePos);

	// standard SFML function
	virtual void draw(sf::RenderWindow& window) const;
};

#endif // !BASEARROW_H