#pragma once
#ifndef LATERALARROW_H

#include <SFML/Graphics.hpp>

#include "constants.h"
#include "BaseArrow.h"

class LateralArrow : public BaseArrow
{
	Direction m_side;

	// initial setup
	void setArrow() override;
	void setStandardTexture() override;
	void setTextCoords() override;

	// when hovering over the arrow
	void setHoverTexture() override;

public:
	LateralArrow(Direction side) : BaseArrow()
	{
		m_side = side;
		setArrow();
		setStandardTexture();
		setTextCoords();
	}

	void arrowInteraction() override;

};


#endif // !LATERALARROW_H

