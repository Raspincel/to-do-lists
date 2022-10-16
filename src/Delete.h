#pragma once
#ifndef  DELETE_H

#include <sfml/Graphics.hpp>

#include <cstdio>

#include "Arrow.h"
#include "BaseListDisplay.h"

class Delete : public BaseListDisplay
{
private:
	Option m_confirmationText;
	Option m_yes;
	Option m_no;
	Arrow m_arrow;

	int m_toDeletion;

	void extractNames() override;
	void setPositions() override;

	void setTexts();
	void deleteList();
	void renderDeletion(sf::RenderWindow& window);

public:
	Delete() : BaseListDisplay()
	{
		m_toDeletion = -1;
		setPositions();
	}

	void renderPage(sf::RenderWindow& window) override;
	void mouseClicked(const sf::Vector2f& mousePos) override;
	void hovering(const sf::Vector2f& mousePos) override;
	void updateDeleting();
	void resetDelete();
};


#endif // ! DELETE_H


