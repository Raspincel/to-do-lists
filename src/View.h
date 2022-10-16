#pragma once
#ifndef VIEW_H

#include <fstream>
#include <sstream>
#include <string>
#include <string_view>

// Classes and etc
#include "Arrow.h"
#include "BaseText.h"
#include "BaseListDisplay.h"
#include "LateralArrow.h"
#include "Option.h"

// Constants and functions
#include "constants.h"

class View : public BaseListDisplay
{
private:
	Option* m_items;
	Arrow m_arrow;

	int m_viewingList;
	int m_numberOfItems;

	int m_numbersPosition;
	int m_itemsFinished;

	void extractNames() override;
	void setPositions() override;

	void setView();
	void setCompletes();
	void addNumberToList(int number);
	void finishList();
	void setFinishedLists();
	void unsetFinishedLists(int target);

public:
	View() : BaseListDisplay()
	{
		m_viewingList = -1;
		m_numberOfPages = 0;
		m_numbersPosition = 0;
		m_itemsFinished = 0;
		setView();
	}

	void renderPage(sf::RenderWindow& window) override;
	void mouseClicked(const sf::Vector2f& mousePos) override;
	void hovering(const sf::Vector2f& mousePos) override;

	void updateList();
	void resetView();

};

#endif // !VIEW_H